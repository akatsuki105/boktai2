	push {lr}
	ldr r1, _080E9094 @ =0x000001DF
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #0x1d
	bhi _080E9170
	lsls r0, r0, #2
	ldr r1, _080E9098 @ =_080E909C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E9094: .4byte 0x000001DF
_080E9098: .4byte _080E909C
_080E909C: @ jump table
	.4byte _080E9114 @ case 0
	.4byte _080E9118 @ case 1
	.4byte _080E911C @ case 2
	.4byte _080E9170 @ case 3
	.4byte _080E9134 @ case 4
	.4byte _080E9134 @ case 5
	.4byte _080E9134 @ case 6
	.4byte _080E913C @ case 7
	.4byte _080E9154 @ case 8
	.4byte _080E912C @ case 9
	.4byte _080E9130 @ case 10
	.4byte _080E916C @ case 11
	.4byte _080E9164 @ case 12
	.4byte _080E9120 @ case 13
	.4byte _080E9124 @ case 14
	.4byte _080E9170 @ case 15
	.4byte _080E9148 @ case 16
	.4byte _080E9140 @ case 17
	.4byte _080E9144 @ case 18
	.4byte _080E9150 @ case 19
	.4byte _080E9138 @ case 20
	.4byte _080E914C @ case 21
	.4byte _080E9160 @ case 22
	.4byte _080E9128 @ case 23
	.4byte _080E9158 @ case 24
	.4byte _080E915C @ case 25
	.4byte _080E9168 @ case 26
	.4byte _080E9170 @ case 27
	.4byte _080E9170 @ case 28
	.4byte _080E911C @ case 29
_080E9114:
	movs r0, #1
	b _080E9172
_080E9118:
	movs r0, #2
	b _080E9172
_080E911C:
	movs r0, #3
	b _080E9172
_080E9120:
	movs r0, #0xb
	b _080E9172
_080E9124:
	movs r0, #0xc
	b _080E9172
_080E9128:
	movs r0, #0x17
	b _080E9172
_080E912C:
	movs r0, #7
	b _080E9172
_080E9130:
	movs r0, #8
	b _080E9172
_080E9134:
	movs r0, #4
	b _080E9172
_080E9138:
	movs r0, #0x10
	b _080E9172
_080E913C:
	movs r0, #5
	b _080E9172
_080E9140:
	movs r0, #0xe
	b _080E9172
_080E9144:
	movs r0, #0xf
	b _080E9172
_080E9148:
	movs r0, #0xd
	b _080E9172
_080E914C:
	movs r0, #0x11
	b _080E9172
_080E9150:
	movs r0, #0x12
	b _080E9172
_080E9154:
	movs r0, #6
	b _080E9172
_080E9158:
	movs r0, #0x14
	b _080E9172
_080E915C:
	movs r0, #0x15
	b _080E9172
_080E9160:
	movs r0, #0x13
	b _080E9172
_080E9164:
	movs r0, #0xa
	b _080E9172
_080E9168:
	movs r0, #0x16
	b _080E9172
_080E916C:
	movs r0, #9
	b _080E9172
_080E9170:
	movs r0, #0
_080E9172:
	pop {r1}
	bx r1
	.align 2, 0
