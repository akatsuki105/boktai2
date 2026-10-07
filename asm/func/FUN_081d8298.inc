	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r2, r0, #0
	ldr r6, _081D8350 @ =0xFFFF0000
	ldr r5, [sp, #0xc]
	ands r5, r6
	ldr r0, _081D8354 @ =0x0000FFF4
	mov sl, r0
	orrs r5, r0
	str r5, [sp, #0xc]
	ldr r3, _081D8358 @ =0x0203B400
	mov sb, r3
	ldr r7, _081D835C @ =0x030046B8
	ldr r1, [r7]
	adds r1, #1
	ldr r0, _081D8360 @ =0x000003FF
	mov r8, r0
	ands r1, r0
	lsls r0, r1, #1
	add r0, sb
	ldrh r3, [r0]
	movs r7, #7
	mov ip, r7
	mov r0, ip
	ands r3, r0
	lsls r3, r3, #0x10
	ldr r4, _081D8364 @ =0x0000FFFF
	adds r0, r4, #0
	ands r0, r5
	orrs r0, r3
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r6
	mov r3, sl
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r3, [sp, #0x14]
	ands r3, r6
	movs r5, #0x18
	orrs r3, r5
	str r3, [sp, #0x14]
	adds r1, #1
	mov r7, r8
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	mov r7, ip
	ands r0, r7
	adds r0, #3
	lsls r0, r0, #0x10
	ands r4, r3
	orrs r4, r0
	str r4, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r5
	str r0, [r3, #4]
	adds r1, #1
	mov r0, r8
	ands r1, r0
	ldr r7, _081D835C @ =0x030046B8
	str r1, [r7]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	movs r1, #3
	ands r0, r1
	adds r0, #3
	adds r2, #0x1c
	str r3, [sp]
	movs r1, #0x3c
	str r1, [sp, #4]
	movs r1, #0x3f
	str r1, [sp, #8]
	movs r1, #2
	add r3, sp, #0xc
	bl FUN_08014730
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D8350: .4byte 0xFFFF0000
_081D8354: .4byte 0x0000FFF4
_081D8358: .4byte 0x0203B400
_081D835C: .4byte 0x030046B8
_081D8360: .4byte 0x000003FF
_081D8364: .4byte 0x0000FFFF
