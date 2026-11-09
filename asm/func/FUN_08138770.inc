	push {r4, lr}
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r2, [r0]
	ldr r4, _0813879C @ =0x00000ADC
	adds r3, r2, r4
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r4, #4
	adds r2, r2, r4
	adds r2, r2, r0
	strh r1, [r2]
	ldrb r0, [r3]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813879C: .4byte 0x00000ADC
