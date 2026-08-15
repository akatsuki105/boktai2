	push {r4, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x8e
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0823B7D4
	subs r0, r0, r1
	asrs r1, r0, #1
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	b _0823B7EE
_0823B7D4:
	adds r0, r3, #0
	adds r0, #0x92
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _0823B7F0
	subs r0, r1, r0
	asrs r1, r0, #1
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	subs r0, r0, r1
_0823B7EE:
	strh r0, [r2, #4]
_0823B7F0:
	movs r1, #4
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	movs r4, #2
	ldrsh r1, [r2, r4]
	subs r1, r0, r1
	adds r0, r3, #0
	adds r0, #0x90
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _0823B81C
	subs r0, r0, r1
	asrs r1, r0, #1
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	b _0823B836
_0823B81C:
	adds r0, r3, #0
	adds r0, #0x94
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	ble _0823B838
	subs r0, r1, r0
	asrs r1, r0, #1
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r2, #4]
	subs r0, r0, r1
_0823B836:
	strh r0, [r2, #4]
_0823B838:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
