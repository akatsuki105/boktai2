	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x6c]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0xe]
	lsls r2, r1, #1
	adds r2, r2, r1
	ldrh r1, [r4, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r5, r0, #0x10
	lsls r2, r2, #0x12
	asrs r1, r2, #0x10
	rsbs r0, r1, #0
	cmp r5, r0
	bge _0824607A
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b _08246080
_0824607A:
	cmp r5, r1
	ble _08246080
	lsrs r3, r2, #0x10
_08246080:
	ldrh r0, [r4, #0xc]
	adds r0, r0, r3
	strh r0, [r4, #0xc]
	lsrs r0, r0, #8
	strb r0, [r4, #9]
	pop {r4, r5}
	pop {r0}
	bx r0
