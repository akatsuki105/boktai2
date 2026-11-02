	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	ldr r4, [sp, #0x18]
	movs r6, #0
	strb r6, [r7, #1]
	ldr r0, [r0, #0x2c]
	asrs r1, r0, #2
	adds r2, r2, r1
	strb r2, [r7, #2]
	strb r3, [r7, #3]
	asrs r0, r0, #1
	adds r0, #0x13
	strh r0, [r7, #4]
	strh r6, [r7, #6]
	str r4, [r7, #8]
	str r6, [r7, #0xc]
	movs r0, #0x20
	str r0, [r7, #0x10]
	adds r5, r7, #0
	adds r5, #0x1c
	ldr r0, _08053628 @ =0x085AB954
	lsls r4, r4, #1
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r0, #0x38
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r1, _0805362C @ =0x085AB740
	ldrb r0, [r7, #3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x54
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0x56
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	adds r1, #2
	ldr r0, _08053630 @ =0x000008FC
	strh r0, [r1]
	str r6, [r7, #0x74]
	movs r0, #1
	strb r0, [r7]
	mov r1, r8
	ldr r0, [r1, #0x4c]
	adds r0, #1
	str r0, [r1, #0x4c]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053628: .4byte 0x085AB954
_0805362C: .4byte 0x085AB740
_08053630: .4byte 0x000008FC
