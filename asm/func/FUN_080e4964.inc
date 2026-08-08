	push {lr}
	adds r3, r0, #0
	ldr r0, _080E4998 @ =0x0000046B
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xe4
	lsls r0, r0, #1
	adds r2, r3, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r3, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _080E4992
	adds r0, r3, #0
	bl _call_via_r2
_080E4992:
	pop {r0}
	bx r0
	.align 2, 0
_080E4998: .4byte 0x0000046B
