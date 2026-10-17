	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08087818
	cmp r0, #0
	beq _08087982
	adds r0, r4, #0
	bl FUN_0808613c
_08087982:
	ldr r1, _08087998 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	bhi _08087A4C
	lsls r0, r0, #2
	ldr r1, _0808799C @ =_080879A0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08087998: .4byte 0x000001F5
_0808799C: .4byte _080879A0
_080879A0: @ jump table
	.4byte _080879E4 @ case 0
	.4byte _080879FC @ case 1
	.4byte _08087A4C @ case 2
	.4byte _080879E4 @ case 3
	.4byte _080879E4 @ case 4
	.4byte _08087A4C @ case 5
	.4byte _08087A4C @ case 6
	.4byte _08087A4C @ case 7
	.4byte _08087A4C @ case 8
	.4byte _08087A4C @ case 9
	.4byte _08087A4C @ case 10
	.4byte _08087A4C @ case 11
	.4byte _08087A4C @ case 12
	.4byte _08087A4C @ case 13
	.4byte _08087A4C @ case 14
	.4byte _08087A18 @ case 15
	.4byte _08087A30 @ case 16
_080879E4:
	ldr r0, _080879F8 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A0C
	b _08087A4C
	.align 2, 0
_080879F8: .4byte 0x03002BE0
_080879FC:
	ldr r0, _08087A10 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A14
_08087A0C:
	movs r0, #1
	b _08087A52
	.align 2, 0
_08087A10: .4byte 0x03002BE0
_08087A14:
	movs r0, #0
	b _08087A52
_08087A18:
	ldr r0, _08087A2C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _08087A40
	b _08087A4C
	.align 2, 0
_08087A2C: .4byte 0x03002BE0
_08087A30:
	ldr r0, _08087A44 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	bne _08087A48
_08087A40:
	movs r0, #0x10
	b _08087A52
	.align 2, 0
_08087A44: .4byte 0x03002BE0
_08087A48:
	movs r0, #0xf
	b _08087A52
_08087A4C:
	ldr r1, _08087A58 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
_08087A52:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08087A58: .4byte 0x000001F5
