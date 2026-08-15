	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0823CA90 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CA5C
	adds r0, r4, #0
	bl FUN_0823c0bc
_0823CA5C:
	ldr r0, _0823CA94 @ =0x030044BC
	ldr r0, [r0]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823CAB0
	adds r0, r4, #0
	bl FUN_0823c450
	ldrh r0, [r4, #0x1c]
	cmp r0, #0
	bne _0823CA9C
	ldr r1, _0823CA98 @ =0x03003540
	adds r0, r4, #0
	adds r0, #0x58
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x5a
	ldrh r0, [r0]
	strh r0, [r1, #2]
	adds r0, r4, #0
	adds r0, #0x5c
	ldrh r0, [r0]
	strh r0, [r1, #4]
	b _0823CAA2
	.align 2, 0
_0823CA90: .4byte 0x030047A4
_0823CA94: .4byte 0x030044BC
_0823CA98: .4byte 0x03003540
_0823CA9C:
	adds r0, r4, #0
	bl FUN_0823c620
_0823CAA2:
	adds r0, r4, #0
	bl FUN_0823c928
	ldr r1, _0823CAD0 @ =0x03003540
	adds r0, r4, #0
	bl Camera_ApplyBounds
_0823CAB0:
	ldr r5, _0823CAD4 @ =0x030047C8
	ldr r4, _0823CAD0 @ =0x03003540
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CAD8
	asrs r0, r0, #8
	b _0823CADE
	.align 2, 0
_0823CAD0: .4byte 0x03003540
_0823CAD4: .4byte 0x030047C8
_0823CAD8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CADE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0823CAF0
	asrs r0, r0, #8
	b _0823CAF6
_0823CAF0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0823CAF6:
	adds r2, r0, #0
	movs r0, #2
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0823CB0A
	asrs r1, r0, #8
	b _0823CB10
_0823CB0A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0823CB10:
	subs r0, r2, r1
	strh r0, [r5, #2]
	adds r0, r2, r1
	strh r0, [r5, #4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
