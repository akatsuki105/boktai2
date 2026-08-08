	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	mov ip, r1
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _0807CD94
	ldr r0, _0807CD80 @ =0x0203B400
	mov r8, r0
	ldr r6, _0807CD84 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _0807CD88 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CD8C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #5
	lsls r0, r0, #0x10
	ldr r1, _0807CD90 @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _0807CE32
	.align 2, 0
_0807CD80: .4byte 0x0203B400
_0807CD84: .4byte 0x030046B8
_0807CD88: .4byte 0x000003FF
_0807CD8C: .4byte 0xFFFF0000
_0807CD90: .4byte 0x0000FFFF
_0807CD94:
	cmp r0, #3
	bne _0807CDF0
	ldr r1, _0807CDDC @ =0x0203B400
	mov r8, r1
	ldr r6, _0807CDE0 @ =0x030046B8
	ldr r1, [r6]
	adds r1, #1
	ldr r3, _0807CDE4 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r0, [r0]
	movs r4, #7
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CDE8 @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r6]
	lsls r1, r1, #1
	add r1, r8
	ldrh r0, [r1]
	ands r0, r4
	subs r0, #3
	lsls r0, r0, #0x10
	ldr r1, _0807CDEC @ =0x0000FFFF
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	b _0807CE32
	.align 2, 0
_0807CDDC: .4byte 0x0203B400
_0807CDE0: .4byte 0x030046B8
_0807CDE4: .4byte 0x000003FF
_0807CDE8: .4byte 0xFFFF0000
_0807CDEC: .4byte 0x0000FFFF
_0807CDF0:
	ldr r6, _0807CE60 @ =0x0203B400
	ldr r4, _0807CE64 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0807CE68 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _0807CE6C @ =0xFFFF0000
	ldr r2, [sp]
	ands r2, r5
	orrs r2, r0
	str r2, [sp]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r0, #0x1f
	ands r1, r0
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	ldr r0, _0807CE70 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_0807CE32:
	ldr r0, [sp, #4]
	ands r0, r5
	str r0, [sp, #4]
	ldr r1, _0807CE74 @ =0x000004C4
	adds r0, r7, r1
	movs r2, #0xe1
	lsls r2, r2, #4
	mov r1, ip
	mov r3, sp
	bl FUN_082467d0
	cmp r0, #0
	blt _0807CE9A
	ldr r1, _0807CE78 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0807CE80
	ldr r0, _0807CE7C @ =0x00000191
	bl PlaySound_082406e0
	b _0807CE9A
	.align 2, 0
_0807CE60: .4byte 0x0203B400
_0807CE64: .4byte 0x030046B8
_0807CE68: .4byte 0x000003FF
_0807CE6C: .4byte 0xFFFF0000
_0807CE70: .4byte 0x0000FFFF
_0807CE74: .4byte 0x000004C4
_0807CE78: .4byte 0x000004C5
_0807CE7C: .4byte 0x00000191
_0807CE80:
	cmp r0, #2
	bne _0807CE90
	ldr r0, _0807CE8C @ =0x00000133
	bl PlaySound_082406e0
	b _0807CE9A
	.align 2, 0
_0807CE8C: .4byte 0x00000133
_0807CE90:
	cmp r0, #3
	bne _0807CE9A
	ldr r0, _0807CEB0 @ =0x00000133
	bl PlaySound_082406e0
_0807CE9A:
	ldr r0, _0807CEB4 @ =0x0000043E
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0807CEB0: .4byte 0x00000133
_0807CEB4: .4byte 0x0000043E
