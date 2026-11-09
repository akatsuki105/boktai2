	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r4, [r1]
	adds r2, #0x8a
	adds r1, r0, r2
	movs r0, #0xae
	lsls r0, r0, #4
	adds r2, r4, r0
	movs r3, #5
_08138726:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _08138726
	ldr r2, _08138740 @ =0x00000ADC
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08138740: .4byte 0x00000ADC
