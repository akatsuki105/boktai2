	.equ	song0999_grp, voicegroup000
	.equ	song0999_pri, 20
	.equ	song0999_rev, reverb_set+128
	.equ	song0999_mvl, 127
	.equ	song0999_key, 0
	.equ	song0999_tbs, 1
	.equ	song0999_exg, 1
	.equ	song0999_cmp, 1

	.section .rodata
	.global	song0999
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

song0999_1:
	.byte	KEYSH , song0999_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 150*song0999_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 104*song0999_mvl/mxv
	.byte		BENDR , 24
	.byte		BEND  , c_v+0
	.byte		N06   , Dn4 , v064
	.byte	W02
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 91*song0999_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 78*song0999_mvl/mxv
	.byte	W01
	.byte		        65*song0999_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 104*song0999_mvl/mxv
	.byte		N60   , Dn4 , v080
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		        c_v-10
	.byte	W02
	.byte		VOL   , 78*song0999_mvl/mxv
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-16
	.byte	W02
	.byte		VOL   , 65*song0999_mvl/mxv
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-20
	.byte	W02
	.byte		        c_v-22
	.byte	W02
	.byte		VOL   , 58*song0999_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W02
	.byte		        c_v-26
	.byte	W02
	.byte		        c_v-28
	.byte	W02
	.byte		VOL   , 52*song0999_mvl/mxv
	.byte		BEND  , c_v-30
	.byte	W02
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-34
	.byte	W02
	.byte		VOL   , 39*song0999_mvl/mxv
	.byte		BEND  , c_v-36
	.byte	W02
	.byte		        c_v-38
	.byte	W02
	.byte		        c_v-40
	.byte	W02
	.byte		VOL   , 32*song0999_mvl/mxv
	.byte		BEND  , c_v-42
	.byte	W02
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-45
	.byte	W02
	.byte		VOL   , 26*song0999_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		        c_v-49
	.byte	W02
	.byte		        c_v-51
	.byte	W02
	.byte		VOL   , 19*song0999_mvl/mxv
	.byte		BEND  , c_v-53
	.byte	W02
	.byte		        c_v-55
	.byte	W01
	.byte		VOL   , 13*song0999_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-57
	.byte	W02
	.byte		VOL   , 9*song0999_mvl/mxv
	.byte		BEND  , c_v-59
	.byte	W02
	.byte		        c_v-61
	.byte	W01
	.byte		VOL   , 6*song0999_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-63
	.byte	W02
	.byte		VOL   , 4*song0999_mvl/mxv
	.byte		BEND  , c_v-64
	.byte	W01
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

song0999_2:
	.byte	KEYSH , song0999_key+0
@ 000   ----------------------------------------
	.byte		VOICE , 114
	.byte		VOL   , 104*song0999_mvl/mxv
	.byte		LFOS  , 12
	.byte		MOD   , 127
	.byte		N14   , An6 , v127
	.byte	W02
	.byte		VOL   , 98*song0999_mvl/mxv
	.byte	W02
	.byte		        91*song0999_mvl/mxv
	.byte	W02
	.byte		        85*song0999_mvl/mxv
	.byte	W02
	.byte		        78*song0999_mvl/mxv
	.byte	W02
	.byte		        72*song0999_mvl/mxv
	.byte	W02
	.byte		        65*song0999_mvl/mxv
	.byte	W03
	.byte		VOICE , 81
	.byte		BENDR , 3
	.byte		MOD   , 0
	.byte		VOL   , 26*song0999_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N32   , An2 , v064
	.byte	W01
	.byte		VOL   , 39*song0999_mvl/mxv
	.byte	W01
	.byte		        52*song0999_mvl/mxv
	.byte	W01
	.byte		        65*song0999_mvl/mxv
	.byte	W01
	.byte		        78*song0999_mvl/mxv
	.byte	W04
	.byte		        72*song0999_mvl/mxv
	.byte	W04
	.byte		        65*song0999_mvl/mxv
	.byte	W04
	.byte		        58*song0999_mvl/mxv
	.byte	W02
	.byte		        52*song0999_mvl/mxv
	.byte	W02
	.byte		        45*song0999_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		VOL   , 39*song0999_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W02
	.byte		VOL   , 32*song0999_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W02
	.byte		VOL   , 26*song0999_mvl/mxv
	.byte		BEND  , c_v-32
	.byte	W02
	.byte		VOL   , 19*song0999_mvl/mxv
	.byte		BEND  , c_v-40
	.byte	W02
	.byte		VOL   , 13*song0999_mvl/mxv
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		VOL   , 6*song0999_mvl/mxv
	.byte		BEND  , c_v-55
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

song0999:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song0999_pri	@ Priority
	.byte	song0999_rev	@ Reverb.

	.word	song0999_grp

	.word	song0999_1
	.word	song0999_2

	.end
