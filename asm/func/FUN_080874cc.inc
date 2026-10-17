	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08087508 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0808751C
	adds r0, r4, #0
	bl FUN_08087440
	adds r0, r4, #0
	bl FUN_08087494
	ldr r0, _0808750C @ =0x00000332
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08087510
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r3]
	subs r0, #1
	strh r0, [r3]
	b _0808751C
	.align 2, 0
_08087508: .4byte 0x030047A4
_0808750C: .4byte 0x00000332
_08087510:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _08087524 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0808751C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08087524: .4byte 0x0000FFFB
