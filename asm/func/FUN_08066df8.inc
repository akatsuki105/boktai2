	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r6, r1]
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	ldr r4, _08066E78 @ =0x03003540
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r5, r6, r1
	strh r0, [r5]
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	ldr r2, _08066E7C @ =0x000003CA
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r1, #0x96
	adds r0, r0, r1
	movs r1, #5
	bl Div
	ldr r2, _08066E80 @ =0x000003C2
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	adds r2, #0xa
	adds r1, r6, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r6, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0823bac8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08066E78: .4byte 0x03003540
_08066E7C: .4byte 0x000003CA
_08066E80: .4byte 0x000003C2
