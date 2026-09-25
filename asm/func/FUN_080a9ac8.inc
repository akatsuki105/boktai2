	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sl
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A9B44
	ldrh r0, [r1]
	movs r5, #8
	subs r5, r5, r0
	ldr r0, _080A9B70 @ =0x0203B400
	mov sb, r0
	ldr r4, _080A9B74 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080A9B78 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	asrs r6, r5, #1
	subs r1, r1, r6
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, r1, r6
	strh r1, [r7, #0x3e]
_080A9B44:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _080A9B62
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9B7C @ =FUN_080a9954
	str r0, [r1]
	ldr r0, _080A9B80 @ =0x00000259
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, sl
	strh r0, [r1]
_080A9B62:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9B70: .4byte 0x0203B400
_080A9B74: .4byte 0x030046B8
_080A9B78: .4byte 0x000003FF
_080A9B7C: .4byte FUN_080a9954
_080A9B80: .4byte 0x00000259
