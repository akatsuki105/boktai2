	push {r4, lr}
	adds r4, r0, #0
	adds r0, #8
	bl FUN_080fa958
	cmp r0, #0
	blt _080FAAC0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r4, r1
	ldr r1, _080FAABC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r2]
	movs r0, #1
	b _080FAACE
	.align 2, 0
_080FAABC: .4byte 0x03002BE0
_080FAAC0:
	ldr r1, _080FAAD4 @ =0x000005C4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
_080FAACE:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080FAAD4: .4byte 0x000005C4
