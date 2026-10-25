	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r2, r0, #0
	cmp r1, #0
	bne _08023CBA
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r7, r2, r0
	ldrh r0, [r7]
	cmp r0, #0
	bne _08023CB4
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _08023CA0 @ =0x0203B400
	mov r8, r2
	ldr r6, _08023CA4 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r5, _08023CA8 @ =0x000003FF
	ands r2, r5
	lsls r1, r2, #1
	add r1, r8
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08023CAC @ =0xFFFF0000
	mov sb, r1
	ldr r4, [sp, #0x10]
	ands r4, r1
	orrs r4, r0
	str r4, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	lsls r0, r2, #1
	add r0, r8
	ldrh r3, [r0]
	asrs r1, r4, #0x10
	adds r1, #0x80
	movs r0, #0x3f
	ands r3, r0
	adds r1, r1, r3
	lsls r1, r1, #0x10
	ldr r0, _08023CB0 @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r2, #1
	ands r2, r5
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x14]
	mov r2, sb
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x14]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #2
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
	ldr r0, [r6]
	adds r0, #1
	ands r0, r5
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	strh r0, [r7]
	b _08023D6E
	.align 2, 0
_08023CA0: .4byte 0x0203B400
_08023CA4: .4byte 0x030046B8
_08023CA8: .4byte 0x000003FF
_08023CAC: .4byte 0xFFFF0000
_08023CB0: .4byte 0x0000FFFF
_08023CB4:
	subs r0, #1
	strh r0, [r7]
	b _08023D6E
_08023CBA:
	movs r0, #0xb5
	lsls r0, r0, #1
	adds r0, r0, r2
	mov sb, r0
	ldrh r0, [r0]
	adds r7, r0, #0
	cmp r7, #0
	bne _08023D68
	movs r1, #0x9e
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r2, _08023D5C @ =0x0203B400
	mov r8, r2
	ldr r6, _08023D60 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r5, _08023D64 @ =0x000003FF
	ands r1, r5
	lsls r2, r1, #1
	add r2, r8
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0x80
	ldrb r2, [r2]
	adds r0, r0, r2
	add r2, sp, #0x10
	strh r0, [r2]
	adds r1, #1
	ands r1, r5
	lsls r0, r1, #1
	add r0, r8
	ldrh r3, [r0]
	adds r4, r2, #0
	ldrh r0, [r4, #2]
	adds r0, #0x80
	movs r2, #0x3f
	ands r3, r2
	adds r0, r0, r3
	strh r0, [r4, #2]
	adds r1, #1
	ands r1, r5
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r4, #4]
	subs r0, #0x80
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #4]
	movs r2, #0xc0
	lsls r2, r2, #6
	movs r0, #0xc
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r7, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	adds r0, r4, #0
	movs r1, #5
	movs r3, #0x40
	bl FUN_08015d3c
	ldr r0, [r6]
	adds r0, #1
	ands r0, r5
	str r0, [r6]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	b _08023D6E
	.align 2, 0
_08023D5C: .4byte 0x0203B400
_08023D60: .4byte 0x030046B8
_08023D64: .4byte 0x000003FF
_08023D68:
	subs r0, #1
	mov r2, sb
	strh r0, [r2]
_08023D6E:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
