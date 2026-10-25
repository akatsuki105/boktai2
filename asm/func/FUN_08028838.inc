	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r2
	ldr r0, _08028898 @ =0x000008E6
	adds r5, r4, r0
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, _0802889C @ =0x000008FC
	adds r6, r4, r1
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r2, _080288A0 @ =0x000008F4
	adds r0, r0, r2
	adds r0, r4, r0
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #9
	bl FUN_0822f588
	ldrh r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080288A4
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080288B4
	.align 2, 0
_08028898: .4byte 0x000008E6
_0802889C: .4byte 0x000008FC
_080288A0: .4byte 0x000008F4
_080288A4:
	ldrh r1, [r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r6, r0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #3
_080288B4:
	orrs r1, r2
	str r1, [r0]
	ldr r5, _08028900 @ =0x000008E6
	adds r3, r4, r5
	ldrh r1, [r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r0, r4, r0
	ldr r1, _08028904 @ =0x00000914
	adds r0, r0, r1
	movs r2, #0xc5
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r0]
	str r2, [r0, #4]
	ldrh r1, [r3]
	lsls r1, r1, #1
	adds r5, #8
	adds r0, r4, r5
	adds r0, r0, r1
	mov r1, r8
	strh r1, [r0]
	ldrh r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08028908 @ =0x000008E8
	adds r1, r4, r2
	adds r1, r1, r0
	movs r0, #0xc
	strh r0, [r1]
	cmp r7, #0
	beq _0802890C
	cmp r7, #1
	bne _0802890C
	movs r1, #0xc8
	b _08028914
	.align 2, 0
_08028900: .4byte 0x000008E6
_08028904: .4byte 0x00000914
_08028908: .4byte 0x000008E8
_0802890C:
	adds r0, r4, #0
	bl FUN_08027ed0
	adds r1, r0, #0
_08028914:
	ldr r0, _08028954 @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r2, r2, r1
	ldr r5, _08028958 @ =0x000008E6
	adds r3, r4, r5
	ldrh r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #5
	adds r5, #0x56
	adds r0, r4, r5
	adds r0, r0, r1
	str r2, [r0]
	ldrh r0, [r3]
	adds r0, #1
	movs r1, #0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _08028942
	strh r1, [r3]
_08028942:
	ldr r2, _0802895C @ =0x000008E4
	adds r0, r4, r2
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028954: .4byte 0x03003584
_08028958: .4byte 0x000008E6
_0802895C: .4byte 0x000008E4
