#ifndef WEBLIB_H
#define WEBLIB_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void init (string * script) {
	*script += "<!DOCTYPE html>\n";
}

class tag {
	public :
		bool ended = false, supportsGlobal, supportsEvents;
		vector<vector<string>> properties;
		vector<vector<string>> eventAttributes;
		vector<vector<string>> globalAttributes;

		tag () {
			vector<vector<string>> empty ({{"", ""}});
			vector<vector<string>> g ({
				{"ondrag", ""},{"onbeforeprint", ""},{"ononline", ""},{"onblur", ""}, {"onsearch", ""},
				{"ondragend", ""},{"onbeforeunload", ""},{"onpagehide", ""},{"onchange", ""}, {"onselect", ""},
				{"ondragenter", ""},{"onerror", ""},{"onpageshow", ""},{"oncontextmenu", ""}, {"onsubmit", ""},
				{"ondragleave", ""},{"onhashchange", ""},{"onpopstate", ""},{"onfocus", ""}, {"onkeydown", ""},
				{"ondragover", ""},{"onload", ""},{"onresize", ""},{"oninput", ""}, {"onkeypress", ""},
				{"ondragstart", ""},{"onmessage", ""},{"onstorage", ""},{"oninvalid", ""}, {"onkeyup", ""},
				{"onafterprint", ""},{"onoffline", ""},{"onunload", ""},{"onreset", ""}, {"onclick", ""},
				{"ondblclick", ""}, {"onmousewheel", ""}, {"onabort", ""}, {"onended", ""}, {"onplay", ""}, {"onstalled", ""},
				{"onmousedown", ""}, {"ondrop", ""}, {"oncanplay", ""}, {"onplaying", ""}, {"onsuspend", ""},
				{"onmousemove", ""}, {"onscroll", ""}, {"oncanplaythrough", ""}, {"onloadeddata", ""}, {"onprogress", ""}, {"ontimeupdate", ""},
				{"onmouseout", ""}, {"oncopy", ""}, {"oncuechange", ""}, {"onloadedmetadata", ""}, {"onratechange", ""}, {"onvolumechange", ""},
				{"onmouseover", ""}, {"oncut", ""}, {"ondurationchange", ""}, {"onloadstart", ""}, {"onseeked", ""}, {"onwaiting", ""}, {"ontoggle", ""},
				{"onmouseup", ""}, {"onpaste", ""}, {"onemptied", ""}, {"onpause", ""}, {"onseeking", ""},
				{"onwheel", ""}
			});
			vector<vector<string>> e ({
				{"accesskey", ""}, {"data-*", ""}, {"dropzone", ""}, {"lang", ""}, {"tabindex", ""},
				{"class", ""}, {"dir", ""}, {"hidden", ""}, {"spellcheck", ""}, {"title", ""},
				{"contenteditable", ""}, {"draggable", ""}, {"id", ""}, {"style", ""}, {"translate", ""}
			});

			this->globalAttributes = ((this->supportsGlobal == true) ? g : empty);
			this->eventAttributes = ((this->supportsEvents == true) ? e : empty);
		}
		void accesskey (string h) {this->eventAttributes[0][1] = h;} void data (string h) {this->eventAttributes[1][1] = h;}
		void dropzone (string h) {this->eventAttributes[2][1] = h;} void lang (string h) {this->eventAttributes[3][1] = h;}
		void tabindex (string h) {this->eventAttributes[4][1] = h;} void class_attribute (string h) {this->eventAttributes[5][1] = h;}
		void dir (string h) {this->eventAttributes[6][1] = h;} void hidden (string h) {this->eventAttributes[7][1] = h;}
		void spellcheck (string h) {this->eventAttributes[8][1] = h;} void title (string h) {this->eventAttributes[9][1] = h;}
		void contenteditable (string h) {this->eventAttributes[10][1] = h;} void draggable (string h) {this->eventAttributes[11][1] = h;}
		void id (string h) {this->eventAttributes[12][1] = h;} void style (string h) {this->eventAttributes[13][1] = h;}
		void translate (string h) {this->eventAttributes[14][1] = h;}


		void ondrag (string h) {this->globalAttributes[0][1] = h;} void ondragend (string h) {this->globalAttributes[5][1] = h;}
		void ondragenter (string h) {this->globalAttributes[10][1] = h;} void ondragleave (string h) {this->globalAttributes[15][1] = h;}
		void ondragover (string h) {this->globalAttributes[20][1] = h;} void ondragstart (string h) {this->globalAttributes[25][1] = h;}
		void onafterprint (string h) {this->globalAttributes[30][1] = h;} void ondblclick (string h) {this->globalAttributes[35][1] = h;}
		void onmousedown (string h) {this->globalAttributes[41][1] = h;} void onmousemove (string h) {this->globalAttributes[46][1] = h;}
		void onmouseout (string h) {this->globalAttributes[52][1] = h;} void onmouseover (string h) {this->globalAttributes[58][1] = h;}
		void onmouseup (string h) {this->globalAttributes[65][1] = h;} void onwheel (string h) {this->globalAttributes[70][1] = h;}
		void onbeforeprint (string h) {this->globalAttributes[1][1] = h;} void onbeforeunload (string h) {this->globalAttributes[6][1] = h;}
		void onerror (string h) {this->globalAttributes[11][1] = h;} void onhashchange (string h) {this->globalAttributes[16][1] = h;}
		void onload (string h) {this->globalAttributes[21][1] = h;} void onmessage (string h) {this->globalAttributes[26][1] = h;}
		void onoffline (string h) {this->globalAttributes[31][1] = h;} void onmousewheel (string h) {this->globalAttributes[36][1] = h;}
		void ondrop (string h) {this->globalAttributes[42][1] = h;} void onscroll (string h) {this->globalAttributes[47][1] = h;}
		void oncopy (string h) {this->globalAttributes[53][1] = h;} void oncut (string h) {this->globalAttributes[59][1] = h;}
		void onpaste (string h) {this->globalAttributes[66][1] = h;} void ononline (string h) {this->globalAttributes[2][1] = h;}
		void onpagehide (string h) {this->globalAttributes[7][1] = h;} void onpageshow (string h) {this->globalAttributes[12][1] = h;}
		void onpopstate (string h) {this->globalAttributes[17][1] = h;} void onresize (string h) {this->globalAttributes[22][1] = h;}
		void onstorage (string h) {this->globalAttributes[27][1] = h;} void onunload (string h) {this->globalAttributes[32][1] = h;}
		void onabort (string h) {this->globalAttributes[37][1] = h;} void oncanplay (string h) {this->globalAttributes[43][1] = h;}
		void oncanplaythrough (string h) {this->globalAttributes[48][1] = h;} void oncuechange (string h) {this->globalAttributes[54][1] = h;}
		void ondurationchange (string h) {this->globalAttributes[60][1] = h;} void onemptied (string h) {this->globalAttributes[67][1] = h;}
		void onblur (string h) {this->globalAttributes[3][1] = h;} void onchange (string h) {this->globalAttributes[8][1] = h;}
		void oncontextmenu (string h) {this->globalAttributes[13][1] = h;} void onfocus (string h) {this->globalAttributes[18][1] = h;}
		void oninput (string h) {this->globalAttributes[23][1] = h;} void oninvalid (string h) {this->globalAttributes[28][1] = h;}
		void onreset (string h) {this->globalAttributes[33][1] = h;} void onended (string h) {this->globalAttributes[38][1] = h;}
		void onloadedmetadata (string h) {this->globalAttributes[55][1] = h;} void onloadstart (string h) {this->globalAttributes[61][1] = h;}
		void onpause (string h) {this->globalAttributes[68][1] = h;} void onsearch (string h) {this->globalAttributes[4][1] = h;}
		void onselect (string h) {this->globalAttributes[9][1] = h;} void onsubmit (string h) {this->globalAttributes[14][1] = h;}
		void onkeydown (string h) {this->globalAttributes[19][1] = h;} void onkeypress (string h) {this->globalAttributes[24][1] = h;}
		void onkeyup (string h) {this->globalAttributes[29][1] = h;} void onclick (string h) {this->globalAttributes[34][1] = h;}
		void onplay (string h) {this->globalAttributes[39][1] = h;} void onplaying (string h) {this->globalAttributes[44][1] = h;}
		void onprogress (string h) {this->globalAttributes[50][1] = h;} void onratechange (string h) {this->globalAttributes[56][1] = h;}
		void onseeking (string h) {this->globalAttributes[69][1] = h;} void onsuspend (string h) {this->globalAttributes[45][1] = h;}
		void onstalled (string h) {this->globalAttributes[40][1] = h;} void ontimeupdate (string h) {this->globalAttributes[51][1] = h;}
		void onvolumechange (string h) {this->globalAttributes[57][1] = h;} void onseeked (string h) {this->globalAttributes[62][1] = h;}
		void onwaiting (string h) {this->globalAttributes[63][1] = h;} void ontoggle (string h) {this->globalAttributes[64][1] = h;}
		void onloadeddata (string h) {this->globalAttributes[49][1] = h;}
};

class link : public tag {
	private:
		string * script;
	public :
		string text;

		link () {
			this->properties = {
				{"href", ""}, {"download", ""},
				{"hreflang", ""}, {"media", ""},
				{"ping", ""}, {"rel", ""},
				{"target", ""}, {"type", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void href (string h) {this->properties[0][1] = h;}
		void download (string h) {this->properties[1][1] = h;}
		void hreflang (string h) {this->properties[2][1] = h;}
		void media (string h) {this->properties[3][1] = h;}
		void ping (string h) {this->properties[4][1] = h;}
		void rel (string h) {this->properties[5][1] = h;}
		void target (string h) {this->properties[6][1] = h;}
		void type (string h) {this->properties[7][1] = h;}

		string getHref () {return this->properties[0][1];}
		string getDownload () {return this->properties[1][1];}
		string getHreflang () {return this->properties[2][1];}
		string getMedia () {return this->properties[3][1];}
		string getPing () {return this->properties[4][1];}
		string getRel () {return this->properties[5][1];}
		string getTarget () {return this->properties[6][1];}
		string getType () {return this->properties[7][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<a ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</a>\n";
				this->ended = true;
			}
		}
};

class paragraph : public tag {
	private:
		string * script;
	public :
		string text;

		paragraph () {
			this->properties = {
				{"align", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void align (string h) {this->properties[0][1] = h;}

		string getAlign () {return this->properties[0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<p ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</p>\n";
				this->ended = true;
			}
		}
};

class header : public tag {
	private:
		string * script;
	public :
		string text;
		string size;

		header (string size) {
			this->supportsGlobal = true;
			this->supportsEvents = true;
			this->size = size;
			this->properties = {
				{"align", ""}
			};
			this->ended = false;
		}

		void align (string h) {this->properties [0][1] = h;}

		string getAlign () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += ("<h" + this->size + " ");
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</h" + this->size + ">\n");
				this->ended = true;
			}
		}
};

class abbr : public tag {
	private:
		string * script;
	public :
		string text;

		abbr (string t) {
			this->supportsGlobal = true;
			this->supportsEvents = true;
			this->properties = {
				{"align", "",}, {"title", t}
			};
			this->ended = false;
		}

		void align (string h) {this->properties [0][1] = h;}
		void title (string h) {this->properties [1][1] = h;}

		string getAlign () {return this->properties [0][1];}
		string getTitle () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += ("\n<abbr ");
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</abbr>\n");
				this->ended = true;
			}
		}
};

class line_break : public tag {
	public:
		line_break () {
			this->supportsGlobal = false;
			this->supportsGlobal = false;
		}

		void add (string * script) {
			if (this->ended) return;
			*script += "<br>\n";
			this->ended = true;
		}
};

class address : public tag {
	private:
		string * script;
	public :
		string text;

		address (string title) {
			this->supportsGlobal = true;
			this->supportsEvents = true;
			this->properties = {
				{"title", title}
			};
			this->ended = false;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += ("<address ");
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</address>\n");
				this->ended = true;
			}
		}
};

class area : public tag {
	private:
		string * script;
	public :

		area () {
			this->properties = {
				{"alt", ""}, {"coords", ""},
				{"download", ""}, {"href", ""},
				{"hreflang", ""}, {"rel", ""},
				{"media", ""}, {"shape", ""},
				{"target", ""}, {"type", ""},
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void alt (string h) {this->properties[0][1] = h;}
		void coords (string h) {this->properties[1][1] = h;}
		void download (string h) {this->properties[2][1] = h;}
		void href (string h) {this->properties[3][1] = h;}
		void hreflang (string h) {this->properties[4][1] = h;}
		void rel (string h) {this->properties[5][1] = h;}
		void media (string h) {this->properties[6][1] = h;}
		void shape (string h) {this->properties[7][1] = h;}
		void target (string h) {this->properties[8][1] = h;}
		void type (string h) {this->properties[9][1] = h;}

		string getAlt () {return this->properties[0][1];}
		string getCoords () {return this->properties[1][1];}
		string getDownload () {return this->properties[2][1];}
		string getHref () {return this->properties[3][1];}
		string getHreflang () {return this->properties[4][1];}
		string getRel () {return this->properties[5][1];}
		string getMedia () {return this->properties[6][1];}
		string getShape () {return this->properties[7][1];}
		string getTarget () {return this->properties[8][1];}
		string getType () {return this->properties[9][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<area ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n");
			this->ended = true;
		}
};

class audio : public tag {
	private:
		string * script;
	public :

		audio () {
			this->properties = {
				{"autoplay", ""}, {"controls", ""},
				{"loop", ""}, {"muted", ""},
				{"preload", ""}, {"src", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void autoplay (string h) {this->properties[0][1] = h;}
		void controls (string h) {this->properties[1][1] = h;}
		void loop (string h) {this->properties[2][1] = h;}
		void muted (string h) {this->properties[3][1] = h;}
		void preload (string h) {this->properties[4][1] = h;}
		void src (string h) {this->properties[5][1] = h;}

		string getAutoplay () {return this->properties[0][1];}
		string getControls () {return this->properties[1][1];}
		string getLoop () {return this->properties[2][1];}
		string getMuted () {return this->properties[3][1];}
		string getPreload () {return this->properties[4][1];}
		string getSRC () {return this->properties[5][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<audio ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n");
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</audio>\n");
				this->ended = true;
			}
		}
};

class bold : public tag {
	private:
		string * script;
	public :
		string text;

		bold () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<b ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</b>\n";
				this->ended = true;
			}
		}
};

class base : public tag {
	private:
		string * script;
	public :

		base (string href) {
			this->properties = {
				{"href", href}, {"target", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = false;
		}

		base (string href, string target) {
			this->properties = {
				{"href", href}, {"target", target}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void href (string h) {this->properties[0][1] = h;}
		void target (string h) {this->properties[1][1] = h;}

		string getHref () {return this->properties[0][1];}
		string getTarget () {return this->properties[1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<base ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n");
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</base>\n";
				this->ended = true;
			}
		}
};

class bi_directional : public tag {
	private:
		string * script;
	public :
		string text;

		bi_directional () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<bdi ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</bdi>\n";
				this->ended = true;
			}
		}
};

class bi_override : public tag {
	private:
		string * script;
	public :
		string text;
		string dir;

		bi_override (string dir) {
			this->dir = dir;
			this->properties = {
				{"dir", dir}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<bdo ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</bdo>\n";
				this->ended = true;
			}
		}
};

class blockquote : public tag {
	private:
		string * script;
	public :
		string text;
		string cite;

		blockquote (string cite) {
			this->cite = cite;
			this->properties = {
				{"cite", cite}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<blockquote ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</blockquote>\n";
				this->ended = true;
			}
		}
};

class body : public tag {
	private:
		string * script;
	public :
		string text;

		body () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<body ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</body>\n";
				this->ended = true;
			}
		}
};

class button : public tag {
	private:
		string * script;
	public :
		string text;

		button () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
			this->properties = {
				{"autofocus", ""}, {"disabled", ""},
				{"form", ""}, {"formaction", ""},
				{"formenctype", ""}, {"formmethod", ""},
				{"formnovalidate", ""}, {"formtarget", ""},
				{"name", ""}, {"type", ""},
				{"value", ""}
			};
			this->ended = false;
		}

		void autofocus (string h) {this->properties [0][1] = h;}
		void disabled (string h) {this->properties [1][1] = h;}
		void form (string h) {this->properties [2][1] = h;}
		void formaction (string h) {this->properties [3][1] = h;}
		void formenctype (string h) {this->properties [4][1] = h;}
		void formmethod (string h) {this->properties [5][1] = h;}
		void formnovalidate (string h) {this->properties [6][1] = h;}
		void formtarget (string h) {this->properties [7][1] = h;}
		void name (string h) {this->properties [8][1] = h;}
		void type (string h) {this->properties [9][1] = h;}
		void value (string h) {this->properties [10][1] = h;}

		string getAutofocus () {return this->properties [0][1];}
		string getState () {return this->properties [1][1];}
		string getForm () {return this->properties [2][1];}
		string getFormaction () {return this->properties [3][1];}
		string getFormenctype () {return this->properties [4][1];}
		string getFormmethod () {return this->properties [5][1];}
		string getFormonvalidate () {return this->properties [6][1];}
		string getFormTarget () {return this->properties [7][1];}
		string getName () {return this->properties [8][1];}
		string getType () {return this->properties [9][1];}
		string getValue () {return this->properties [10][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += ("<button ");
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</button>\n");
				this->ended = true;
			}
		}
};

class canvas : public tag {
	private:
		string * script;
	public :
		string text;

		canvas () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
			this->properties = {
				{"width", ""}, {"height", ""}
			};
			this->ended = false;
		}

		void width (string h) {this->properties [0][1] = h;}
		void height (string h) {this->properties [1][1] = h;}

		string getWidth () {return this->properties [0][1];}
		string getHeight () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += ("<canvas ");
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += ("</canvas>\n");
				this->ended = true;
			}
		}
};

class caption : public tag {
	private:
		string * script;
	public :
		string text;

		caption () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<caption ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</caption>\n";
				this->ended = true;
			}
		}
};

class center : public tag {
	private:
		string * script;
	public :
		string text;

		center () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<center ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</center>\n";
				this->ended = true;
			}
		}
};

class italic : public tag {
	private:
		string * script;
	public :
		string text;

		italic () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<i ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</i>\n";
				this->ended = true;
			}
		}
};

class code : public tag {
	private:
		string * script;
	public :
		string text;

		code () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<code ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</code>\n";
				this->ended = true;
			}
		}
};

class color : public tag {
	private:
		string * script;
	public :
		string text;

		color (string span) {
			this->properties = {
				{"span", span}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		color () {
			this->properties = {
				{"span", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void span (string h) {this->properties [0][1] = h;}

		string getSpan () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<col ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</col>\n";
				this->ended = true;
			}
		}
};

class datalist : public tag {
	private:
		string * script;
	public :
		string text;

		datalist (string span) {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<datalist ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</datalist>\n";
				this->ended = true;
			}
		}
};

class deleted_text : public tag {
	private:
		string * script;
	public :
		string text;

		deleted_text (string span) {
			this->properties = {
				{"url", ""}, {"date", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void url (string h) {this->properties [0][1] = h;}
		void date (string h) {this->properties [1][1] = h;}

		 string getUrl () {return this->properties [0][1];}
		 string getDate () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<del ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</del>\n";
				this->ended = true;
			}
		}
};

class dialog_box : public tag {
	private:
		string * script;
	public :
		string text;

		dialog_box () {
			this->properties = {
				{"open", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void open (string h) {this->properties [0][1] = h;}

		 string getOpen () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<dialog ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</dialog>\n";
				this->ended = true;
			}
		}
};

class division : public tag {
	private:
		string * script;
	public :
		string text;

		division () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<div ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</div>\n";
				this->ended = true;
			}
		}
};

class emphasize : public tag {
	private:
		string * script;
	public :
		string text;

		emphasize () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<em ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</em>\n";
				this->ended = true;
			}
		}
};

class embed : public tag {
	private:
		string * script;
	public :
		string text;

		embed (string span) {
			this->properties = {
				{"height", ""}, {"width", ""},
				{"type", ""}, {"src", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void height (string h) {this->properties [0][1] = h;}
		void width (string h) {this->properties [1][1] = h;}
		void type (string h) {this->properties [2][1] = h;}
		void src (string h) {this->properties [3][1] = h;}

		string getHeight () {return this->properties [0][1];}
		string getWidth () {return this->properties [1][1];}
		string getType () {return this->properties [2][1];}
		string getSource () {return this->properties [3][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<embed ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</embed>\n";
				this->ended = true;
			}
		}
};

class fieldset : public tag {
	private:
		string * script;
	public :
		string text;

		fieldset (string span) {
			this->properties = {
				{"form", ""}, {"disabled", ""},
				{"name", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void form (string h) {this->properties [0][1] = h;}
		void disabled (string h) {this->properties [1][1] = h;}
		void name (string h) {this->properties [2][1] = h;}

		string getForm () {return this->properties [0][1];}
		string getDisabled () {return this->properties [1][1];}
		string getState () {return this->properties [2][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<fieldset ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</fieldset>\n";
				this->ended = true;
			}
		}
};

class head : public tag {
	private:
		string * script;
	public :
		string text;

		head () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<head ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</head>\n";
				this->ended = true;
			}
		}
};

class horizontal_row : public tag {
	public:
		horizontal_row () {
			this->supportsGlobal = false;
			this->supportsEvents = false;
		}

		void add (string * script) {
			if (this->ended) return;
			*script += "<hr>\n";
			this->ended = true;
		}
};

class inline_frame : public tag {
	private:
		string * script;
	public :
		string text;

		inline_frame (string span) {
			this->properties = {
				{"height", ""}, {"sandbox", ""},
				{"name", ""}, {"src", ""},
				{"srcdoc", ""}, {"width", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void height (string h) {this->properties [0][1] = h;}
		void sandbox (string h) {this->properties [1][1] = h;}
		void name (string h) {this->properties [2][1] = h;}
		void src (string h) {this->properties [3][1] = h;}
		void srcdoc (string h) {this->properties [4][1] = h;}
		void width (string h) {this->properties [5][1] = h;}

		string getHeight () {return this->properties [0][1];}
		string getSandbox () {return this->properties [1][1];}
		string getName () {return this->properties [2][1];}
		string getSource () {return this->properties [3][1];}
		string getSrcdoc () {return this->properties [4][1];}
		string getWidth () {return this->properties [5][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<iframe ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</iframe>\n";
				this->ended = true;
			}
		}
};

class image : public tag {
	private:
		string * script;
	public:
		string text;

		image () {
			this->properties = {
				{"alt", ""}, {"crossorigin", ""},
				{"height", ""}, {"ismap", ""},
				{"longdesc", ""}, {"sizes", ""},
				{"src", ""}, {"srcset", ""},
				{"usemap", ""}, {"width", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void alt (string h) {this->properties [0][1] = h;}
		void crossorigin (string h) {this->properties [1][1] = h;}
		void height (string h) {this->properties [2][1] = h;}
		void ismap (string h) {this->properties [3][1] = h;}
		void longdescription (string h) {this->properties [4][1] = h;}
		void sizes (string h) {this->properties [5][1] = h;}
		void source (string h) {this->properties [6][1] = h;}
		void sourceset (string h) {this->properties [7][1] = h;}
		void usemap (string h) {this->properties [8][1] = h;}
		void width (string h) {this->properties [9][1] = h;}

		string getAlt () {return this->properties [0][1];}
		string getCrossorigin () {return this->properties [1][1];}
		string getHeight () {return this->properties [2][1];}
		string getIsmap () {return this->properties [3][1];}
		string getLongdescription () {return this->properties [4][1];}
		string getSizes () {return this->properties [5][1];}
		string getSource () {return this->properties [6][1];}
		string getSourceset () {return this->properties [7][1];}
		string getUsemap () {return this->properties [8][1];}
		string getWidth () {return this->properties [9][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<img ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
			this->ended = true;
		}
};

class input : public tag {
	private:
		string * script;
	public:
		string text;

		input () {
			this->properties = {
				{"accept", ""}, {"alt", ""},
				{"autocomplete", ""}, {"autofocus", ""},
				{"checked", ""}, {"dirname", ""},
				{"disabled", ""}, {"form", ""},
				{"formaction", ""}, {"formenctype", ""},
				{"formmethod", ""}, {"formnovalidate", ""},
				{"formtarget", ""}, {"height", ""},
				{"list", ""}, {"max", ""},
				{"maxlength", ""}, {"min", ""},
				{"multiple", ""}, {"name", ""},
				{"pattern", ""}, {"placeholder", ""},
				{"readonly", ""}, {"required", ""},
				{"size", ""}, {"src", ""},
				{"step", ""}, {"type", ""},
				{"value", ""}, {"width", ""},
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void accept (string h) {this->properties [0][1] = h;}
		void alt (string h) {this->properties [1][1] = h;}
		void autocomplete (string h) {this->properties [2][1] = h;}
		void autofocus (string h) {this->properties [3][1] = h;}
		void checked (string h) {this->properties [4][1] = h;}
		void dirname (string h) {this->properties [5][1] = h;}
		void disabled (string h) {this->properties [6][1] = h;}
		void form (string h) {this->properties [7][1] = h;}
		void formaction (string h) {this->properties [8][1] = h;}
		void formenctype (string h) {this->properties [9][1] = h;}
		void formmethod (string h) {this->properties [10][1] = h;}
		void formnovalidate (string h) {this->properties [11][1] = h;}
		void formtarget (string h) {this->properties [12][1] = h;}
		void height (string h) {this->properties [13][1] = h;}
		void list (string h) {this->properties [14][1] = h;}
		void max (string h) {this->properties [15][1] = h;}
		void maxlength (string h) {this->properties [16][1] = h;}
		void min (string h) {this->properties [17][1] = h;}
		void multiple (string h) {this->properties [18][1] = h;}
		void name (string h) {this->properties [19][1] = h;}
		void pattern (string h) {this->properties [20][1] = h;}
		void placeholder (string h) {this->properties [21][1] = h;}
		void readonly (string h) {this->properties [22][1] = h;}
		void required (string h) {this->properties [23][1] = h;}
		void size (string h) {this->properties [24][1] = h;}
		void src (string h) {this->properties [25][1] = h;}
		void step (string h) {this->properties [26][1] = h;}
		void type (string h) {this->properties [27][1] = h;}
		void value (string h) {this->properties [28][1] = h;}
		void width (string h) {this->properties [29][1] = h;}

		string getAccept () {return this->properties [0][1];}
		string getAlt () {return this->properties [1][1];}
		string getAutoComplete () {return this->properties [2][1];}
		string getAutofocus () {return this->properties [3][1];}
		string getChecked () {return this->properties [4][1];}
		string getDirname () {return this->properties [5][1];}
		string getDisabled () {return this->properties [6][1];}
		string getForm () {return this->properties [7][1];}
		string getFormaction () {return this->properties [8][1];}
		string getFormenctype () {return this->properties [9][1];}
		string getFormmethod () {return this->properties [10][1];}
		string getFormonvalidate () {return this->properties [11][1];}
		string getFormtarget () {return this->properties [12][1];}
		string getHeight () {return this->properties [13][1];}
		string getList () {return this->properties [14][1];}
		string getMax () {return this->properties [15][1];}
		string getMaxlength () {return this->properties [16][1];}
		string getMin () {return this->properties [17][1];}
		string getMultiple () {return this->properties [18][1];}
		string getName () {return this->properties [19][1];}
		string getPattern () {return this->properties [20][1];}
		string getPlaceholder () {return this->properties [21][1];}
		string getReadonly () {return this->properties [22][1];}
		string getRequired () {return this->properties [23][1];}
		string getSize () {return this->properties [24][1];}
		string getSource () {return this->properties [25][1];}
		string getStep () {return this->properties [26][1];}
		string getType () {return this->properties [27][1];}
		string getValue () {return this->properties [28][1];}
		string getWidth () {return this->properties [29][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<input ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
			this->ended = true;
		}
};

class label : public tag {
	private:
		string * script;
	public :
		string text;

		label () {
			this->properties = {
				{"for", ""}, {"from", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void _for (string h) {this->properties [0][1] = h;}
		void from (string h) {this->properties [1][1] = h;}

		string getFor () {return this->properties [0][1];}
		string getFrom () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<label ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</label>\n";
				this->ended = true;
			}
		}
};

class inlineFrame_caption : public tag {
	private:
		string * script;
	public :
		string text;

		inlineFrame_caption () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<legend ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</legend>\n";
				this->ended = true;
			}
		}
};

class list_item : public tag {
	private:
		string * script;
	public :
		string text;

		list_item () {
			this->properties = {
				{"value", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void value (string h) {this->properties [0][1] = h;}

		string getValue () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<li ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</li>\n";
				this->ended = true;
			}
		}
};

class external_link : public tag {
	private:
		string * script;
	public:
		string text;

		external_link () {
			this->properties = {
				{"crossorigin", ""}, {"href", ""},
				{"hreflang", ""}, {"media", ""},
				{"rel", ""}, {"sizes", ""},
				{"type", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void crossorigin (string h) {this->properties [0][1] = h;}
		void href (string h) {this->properties [1][1] = h;}
		void hreflang (string h) {this->properties [2][1] = h;}
		void media (string h) {this->properties [3][1] = h;}
		void rel (string h) {this->properties [4][1] = h;}
		void sizes (string h) {this->properties [5][1] = h;}
		void type (string h) {this->properties [6][1] = h;}

		string getCrossorigin () {return this->properties [0][1];}
		string getHref () {return this->properties [1][1];}
		string getHreflang () {return this->properties [2][1];}
		string getMedia () {return this->properties [3][1];}
		string getRel () {return this->properties [4][1];}
		string getSizes () {return this->properties [5][1];}
		string getType () {return this->properties [6][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<link ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}
		void end () {
			if (!this->ended) {
				*(this->script) += "</link>\n";
				this->ended = true;
			}
		}
};

class map_images : public tag {
	private:
		string * script;
	public:
		string text;

		map_images (string name) {
			this->properties = {
				{"name", name}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void name (string h) {this->properties [0][1] = h;}

		string getName () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<map ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}
		void end () {
			if (!this->ended) {
				*(this->script) += "</map>\n";
				this->ended = true;
			}
		}
};

class mark_text : public tag {
	private:
		string * script;
	public:
		string text;

		mark_text () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<mark ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}
		void end () {
			if (!this->ended) {
				*(this->script) += "</mark>\n";
				this->ended = true;
			}
		}
};

class meta : public tag {
	private:
		string * script;
	public:

		meta (string ) {
			this->properties = {
				{"charset", }, {"content", ""},
				{"http-equiv", }, {"name", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = false;
		}

		void charset (string h) {this->properties [0][1] = h;}
		void content (string h) {this->properties [1][1] = h;}
		void http_equiv (string h) {this->properties [2][1] = h;}
		void name (string h) {this->properties [3][1] = h;}

		string getCharset () {return this->properties [0][1];}
		string getContent () {return this->properties [1][1];}
		string getHttp_equiv () {return this->properties [2][1];}
		string getName () {return this->properties [3][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<meta ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n");
		}
		void end () {
			if (!this->ended) {
				*(this->script) += "</meta>\n";
				this->ended = true;
			}
		}
};

class meter : public tag {
	private:
		string * script;
	public:

		meter (string ) {
			this->properties = {
				{"form", }, {"high", ""},
				{"low", }, {"max", ""},
				{"min", }, {"optimum", ""},
				{"value", }
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void form (string h) {this->properties [0][1] = h;}
		void high (string h) {this->properties [1][1] = h;}
		void low (string h) {this->properties [2][1] = h;}
		void max (string h) {this->properties [3][1] = h;}
		void min (string h) {this->properties [4][1] = h;}
		void optimum (string h) {this->properties [5][1] = h;}
		void value (string h) {this->properties [6][1] = h;}

		string getForm () {return this->properties [0][1];}
		string getHigh () {return this->properties [1][1];}
		string getLow () {return this->properties [2][1];}
		string getMax () {return this->properties [3][1];}
		string getMin () {return this->properties [4][1];}
		string getOptimum () {return this->properties [5][1];}
		string getValue () {return this->properties [6][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<meter ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n");
		}
		void end () {
			if (!this->ended) {
				*(this->script) += "</meter>\n";
				this->ended = true;
			}
		}
};

class ordered_list : public tag {
	private:
		string * script;
	public :
		string text;

		ordered_list () {
			this->properties = {
				{"reversed", ""}, {"start", ""},
				{"type", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void reversed (string h) {this->properties [0][1] = h;}
		void start (string h) {this->properties [1][1] = h;}
		void type (string h) {this->properties [2][1] = h;}

		string getReversed () {return this->properties [0][1];}
		string getStart () {return this->properties [1][1];}
		string getType () {return this->properties [2][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<ol ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</ol>\n";
				this->ended = true;
			}
		}
};

class options_group : public tag {
	private:
		string * script;
	public :
		string text;

		options_group () {
			this->properties = {
				{"label", ""}, {"disabled", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void label (string h) {this->properties [0][1] = h;}
		void disabled (string h) {this->properties [1][1] = h;}

		string getLabel () {return this->properties [0][1];}
		string getDisabled () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<optgroup ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</optgroup>\n";
				this->ended = true;
			}
		}
};

class option : public tag {
	private:
		string * script;
	public :
		string text;

		option () {
			this->properties = {
				{"label", ""}, {"disabled", ""},
				{"value", ""}, {"selected", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void label (string h) {this->properties [0][1] = h;}
		void disabled (string h) {this->properties [1][1] = h;}
		void value (string h) {this->properties [2][1] = h;}
		void selected (string h) {this->properties [3][1] = h;}

		string getLabel () {return this->properties [0][1];}
		string getDisabled () {return this->properties [1][1];}
		string getValue () {return this->properties [2][1];}
		string getSelected () {return this->properties [4][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<option ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</option>\n";
				this->ended = true;
			}
		}
};

class output : public tag {
	private:
		string * script;
	public :
		string text;

		output () {
			this->properties = {
				{"for", ""}, {"form", ""},
				{"name", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void _for (string h) {this->properties [0][1] = h;}
		void form (string h) {this->properties [1][1] = h;}
		void name (string h) {this->properties [2][1] = h;}

		string getFor () {return this->properties [0][1];}
		string getFrom () {return this->properties [1][1];}
		string getName () {return this->properties [2][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<output ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</output>\n";
				this->ended = true;
			}
		}
};

class parameter : public tag {
	private:
		string * script;
	public :
		string text;

		parameter () {
			this->properties = {
				{"name", ""}, {"value", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void name (string h) {this->properties [0][1] = h;}
		void value (string h) {this->properties [1][1] = h;}

		string getName () {return this->properties [0][1];}
		string getValue () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<param ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</param>\n";
				this->ended = true;
			}
		}
};

class pre_formatted : public tag {
	private:
		string * script;
	public :
		string text;

		pre_formatted () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<pre ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</pre>\n";
				this->ended = true;
			}
		}
};

class progress_bar : public tag {
	private:
		string * script;
	public :
		string text;

		progress_bar () {
			this->properties = {
				{"max", ""}, {"value", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void max (string h) {this->properties [0][1] = h;}
		void value (string h) {this->properties [1][1] = h;}

		string getMax () {return this->properties [0][1];}
		string getValue () {return this->properties [1][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<progress ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</progress>\n";
				this->ended = true;
			}
		}
};

class dropdown_list : public tag {
	private:
		string * script;
	public :
		string text;

		dropdown_list () {
			this->properties = {
				{"autofocus", ""}, {"disabled", ""},
				{"form", ""}, {"multiple", ""},
				{"name", ""}, {"required", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void autofocus (string h) {this->properties [0][1] = h;}
		void disabled (string h) {this->properties [1][1] = h;}
		void form (string h) {this->properties [2][1] = h;}
		void multiple (string h) {this->properties [3][1] = h;}
		void name (string h) {this->properties [4][1] = h;}
		void required (string h) {this->properties [5][1] = h;}

		string getAutofocus () {return this->properties [0][1];}
		string getDisabled () {return this->properties [1][1];}
		string getForm () {return this->properties [2][1];}
		string getMultiple () {return this->properties [3][1];}
		string getName () {return this->properties [4][1];}
		string getRequired () {return this->properties [5][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<select ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</select>\n";
				this->ended = true;
			}
		}
};

class small_text : public tag {
	private:
		string * script;
	public :
		string text;

		small_text () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<small ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</small>\n";
				this->ended = true;
			}
		}
};

class media_source : public tag {
	private:
		string * script;
	public :
		string text;

		media_source () {
			this->properties = {
				{"src", ""}, {"srcset", ""},
				{"media", ""}, {"sizes", ""},
				{"type", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void src (string h) {this->properties [0][1] = h;}
		void srcset (string h) {this->properties [1][1] = h;}
		void media (string h) {this->properties [2][1] = h;}
		void sizes (string h) {this->properties [3][1] = h;}
		void type (string h) {this->properties [4][1] = h;}

		string getSource () {return this->properties [0][1];}
		string getSourceset () {return this->properties [1][1];}
		string getMedia () {return this->properties [2][1];}
		string getSizes () {return this->properties [3][1];}
		string getType () {return this->properties [4][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<source ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</source>\n";
				this->ended = true;
			}
		}
};

class span : public tag {
	private:
		string * script;
	public :
		string text;

		span () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<span ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</span>\n";
				this->ended = true;
			}
		}
};

class subscript : public tag {
	private:
		string * script;
	public :
		string text;

		subscript () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<sub ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</sub>\n";
				this->ended = true;
			}
		}
};

class superscript : public tag {
	private:
		string * script;
	public :
		string text;

		superscript () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<sup ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</sup>\n";
				this->ended = true;
			}
		}
};

class details : public tag {
	private:
		string * script;
	public :
		string text;

		details () {
			this->properties = {
				{"open", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void open (string h) {this->properties [0][1] = h;}

		string getOpen () {return this->properties [0][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<details ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</details>\n";
				this->ended = true;
			}
		}
};

class summary : public tag {
	private:
		string * script;
	public :
		string text;

		summary () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<summary ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</summary>\n";
				this->ended = true;
			}
		}
};

class table : public tag {
	private:
		string * script;
	public :
		string text;

		table () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<table ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</table>\n";
				this->ended = true;
			}
		}
};

class table_body : public tag {
	private:
		string * script;
	public :
		string text;

		table_body () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<tbody ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</tbody>\n";
				this->ended = true;
			}
		}
};

class table_component : public tag {
	private:
		string * script;
	public :
		string text;

		table_component () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<td ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</td>\n";
				this->ended = true;
			}
		}
};

class template : public tag {
	private:
		string * script;
	public :
		string text;

		template () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<template ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</template>\n";
				this->ended = true;
			}
		}
};

class sizeable_text : public tag {
	private:
		string * script;
	public:
		string text;

		sizeable_text () {
			this->properties = {
				{"autofocus", ""}, {"cols", ""},
				{"dirname", ""}, {"disabled", ""},
				{"form", ""}, {"maxlength", ""},
				{"name", ""}, {"placeholder", ""},
				{"readonly", ""}, {"required", ""},
				{"rows", ""}, {"wrap", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void autofocus (string h) {this->properties [0][1] = h;}
		void cols (string h) {this->properties [1][1] = h;}
		void dirname (string h) {this->properties [2][1] = h;}
		void disabled (string h) {this->properties [3][1] = h;}
		void form (string h) {this->properties [4][1] = h;}
		void maxlength (string h) {this->properties [5][1] = h;}
		void name (string h) {this->properties [6][1] = h;}
		void placeholder (string h) {this->properties [7][1] = h;}
		void readonly (string h) {this->properties [8][1] = h;}
		void required (string h) {this->properties [9][1] = h;}
		void rows (string h) {this->properties [10][1] = h;}
		void wrap (string h) {this->properties [11][1] = h;}

		string getAutofocus () {return this->properties [0][1];}
		string getCols () {return this->properties [1][1];}
		string getDirname () {return this->properties [2][1];}
		string getDisabled () {return this->properties [3][1];}
		string getForm () {return this->properties [4][1];}
		string getMaxlength () {return this->properties [5][1];}
		string getName () {return this->properties [6][1];}
		string getPlaceholder () {return this->properties [7][1];}
		string getReadonly () {return this->properties [8][1];}
		string getRequired () {return this->properties [9][1];}
		string getRows () {return this->properties [10][1];}
		string getWrap () {return this->properties [11][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<textarea ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</textarea>\n";
				this->ended = true;
			}
		}
};

class webpage_title : public tag {
	private:
		string * script;
	public :
		string text;

		webpage_title () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<title ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</title>\n";
				this->ended = true;
			}
		}
};

class media_track : public tag {
	private:
		string * script;
	public:
		string text;

		media_track () {
			this->properties = {
				{"default", ""}, {"kind", ""},
				{"label", ""}, {"src", ""},
				{"srclang", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void _default (string h) {this->properties [0][1] = h;}
		void kind (string h) {this->properties [1][1] = h;}
		void label (string h) {this->properties [2][1] = h;}
		void source (string h) {this->properties [3][1] = h;}
		void srclang (string h) {this->properties [4][1] = h;}

		string getDefault () {return this->properties [0][1];}
		string getKind () {return this->properties [1][1];}
		string getLabel () {return this->properties [2][1];}
		string getSource () {return this->properties [3][1];}
		string getSrclang () {return this->properties [4][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<track ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</track>\n";
				this->ended = true;
			}
		}
};

class underline_text : public tag {
	private:
		string * script;
	public :
		string text;

		underline_text () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<u ";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</u>\n";
				this->ended = true;
			}
		}
};

class unordered_list : public tag {
	private:
		string * script;
	public :
		string text;

		unordered_list () {
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<ul ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</ul>\n";
				this->ended = true;
			}
		}
};

class suitable_lb : public tag {
	public:
		suitable_lb () {
			this->supportsGlobal = false;
			this->supportsGlobal = false;
		}

		void add (string * script) {
			if (this->ended) return;
			*script += "<wbr>\n";
			this->ended = true;
		}
};

class video : public tag {
	private:
		string * script;
	public:
		string text;

		video () {
			this->properties = {
				{"autoplay", ""}, {"controls", ""},
				{"height", ""}, {"loop", ""},
				{"muted", ""}, {"poster", ""},
				{"preload", ""}, {"src", ""},
				{"width", ""}
			};
			this->supportsGlobal = true;
			this->supportsEvents = true;
		}

		void autoplay (string h) {this->properties [0][1] = h;}
		void controls (string h) {this->properties [1][1] = h;}
		void height (string h) {this->properties [2][1] = h;}
		void loop (string h) {this->properties [3][1] = h;}
		void muted (string h) {this->properties [4][1] = h;}
		void poster (string h) {this->properties [5][1] = h;}
		void preload (string h) {this->properties [6][1] = h;}
		void source (string h) {this->properties [7][1] = h;}
		void width (string h) {this->properties [8][1] = h;}

		string getAutoplay () {return this->properties [0][1];}
		string getControls () {return this->properties [1][1];}
		string getHeight () {return this->properties [2][1];}
		string getLoop () {return this->properties [3][1];}
		string getMuted () {return this->properties [4][1];}
		string getPoster () {return this->properties [5][1];}
		string getPreload () {return this->properties [6][1];}
		string getSource () {return this->properties [7][1];}
		string getWidth () {return this->properties [8][1];}

		void add (string * script) {
			if (this->ended) return;
			this->script = script;
			*script += "<video ";
			for (vector<string> p:this->properties)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->globalAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			for (vector<string> p:this->eventAttributes)
				*script+= (p [1] != "") ? (p[0] + "=\"" + p[1] + "\" ") : "";
			*script += (">\n" + this->text);
		}

		void end () {
			if (!this->ended) {
				*(this->script) += "</video>\n";
				this->ended = true;
			}
		}
};
#endif