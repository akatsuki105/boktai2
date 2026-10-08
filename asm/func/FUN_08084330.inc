	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	beq _08084340
	cmp r0, #2
	beq _08084388
	b _080843A4
_08084340:
	ldr r0, [r4, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808435E
	ldr r0, _0808437C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08084380 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r4, #0
	bl FUN_08081d18
_0808435E:
	adds r0, r4, #0
	bl FUN_08083eac
	ldr r1, _08084384 @ =0x085ABF54
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
	b _080843A4
	.align 2, 0
_0808437C: .4byte 0x030046A0
_08084380: .4byte 0x00000942
_08084384: .4byte 0x085ABF54
_08084388:
	adds r0, r4, #0
	movs r1, #8
	bl PlayerLink_SetFlag35a
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
_080843A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
