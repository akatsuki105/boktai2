	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0809A6A0 @ =0x085ACFDC
	ldr r2, _0809A6A4 @ =0x00000F56
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_0808b4c0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0809A6A0: .4byte 0x085ACFDC
_0809A6A4: .4byte 0x00000F56
