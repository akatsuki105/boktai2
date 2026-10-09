	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	movs r0, #0
	mov sl, r0
	ldr r2, _0809AA38 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r4
	ldr r1, _0809AA3C @ =0x0000FF88
	orrs r0, r1
	adds r1, #0x77
	adds r4, r0, #0
	ands r4, r1
	ands r5, r2
	movs r1, #0
	mov r8, r1
	ldr r7, _0809AA40 @ =0x0000108C
	add r7, sb
	ldr r2, _0809AA44 @ =0x00001084
	add r2, sb
	str r2, [sp]
_0809A9E2:
	ldr r0, _0809AA48 @ =0x00000F58
	add r0, sb
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809AA6C
	ldr r6, [sp]
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r2, r8
	adds r2, #0x64
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sb
	adds r1, #0x60
	movs r3, #1
	bl MainSprite_SetPose
	mov r0, sl
	mov r2, r8
	subs r1, r0, r2
	lsls r1, r1, #0x14
	ldr r0, _0809AA4C @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	str r4, [r7, #0x18]
	str r5, [r7, #0x1c]
	ldr r0, _0809AA50 @ =0x00000F57
	add r0, sb
	ldrb r0, [r0]
	cmp r8, r0
	bne _0809AA58
	adds r0, r6, #0
	ldr r1, _0809AA54 @ =0x000002A5
	bl MainSprite_SetPltt
	b _0809AA60
	.align 2, 0
_0809AA38: .4byte 0xFFFF0000
_0809AA3C: .4byte 0x0000FF88
_0809AA40: .4byte 0x0000108C
_0809AA44: .4byte 0x00001084
_0809AA48: .4byte 0x00000F58
_0809AA4C: .4byte 0x0000FFFF
_0809AA50: .4byte 0x00000F57
_0809AA54: .4byte 0x000002A5
_0809AA58:
	adds r0, r6, #0
	ldr r1, _0809AAE0 @ =0x000002A6
	bl MainSprite_SetPltt
_0809AA60:
	adds r7, #0x60
	ldr r0, [sp]
	adds r0, #0x60
	str r0, [sp]
	movs r1, #1
	add sl, r1
_0809AA6C:
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #9
	ble _0809A9E2
	mov r1, sl
	cmp r1, #9
	bgt _0809AACE
	lsls r0, r1, #1
	add r0, sl
	lsls r0, r0, #5
	ldr r2, _0809AAE4 @ =0x0000108C
	adds r1, r0, r2
	mov r2, sb
	adds r6, r1, r2
	ldr r1, _0809AAE8 @ =0x00001084
	adds r0, r0, r1
	adds r7, r0, r2
_0809AA90:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	mov r2, sl
	lsls r1, r2, #0x14
	ldr r0, _0809AAEC @ =0x0000FFFF
	ands r0, r4
	adds r4, r0, #0
	orrs r4, r1
	str r4, [r6, #0x18]
	str r5, [r6, #0x1c]
	adds r0, r7, #0
	mov r1, sb
	adds r1, #0x60
	movs r2, #0x63
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r7, #0
	ldr r1, _0809AAF0 @ =0x000002A5
	bl MainSprite_SetPltt
	adds r6, #0x60
	adds r7, #0x60
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #9
	ble _0809AA90
_0809AACE:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809AAE0: .4byte 0x000002A6
_0809AAE4: .4byte 0x0000108C
_0809AAE8: .4byte 0x00001084
_0809AAEC: .4byte 0x0000FFFF
_0809AAF0: .4byte 0x000002A5
