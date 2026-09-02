	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x20]
	mov sb, r1
	movs r1, #0
	movs r2, #0
	mov r0, sb
	strb r1, [r0, #1]
	movs r0, #1
	mov r3, sb
	strb r0, [r3]
	strh r2, [r3, #6]
	strb r1, [r3, #9]
	strh r2, [r3, #0xa]
	movs r4, #0xac
	lsls r4, r4, #2
	add r4, sb
	ldr r1, _08245E44 @ =0x00008202
	adds r0, r4, #0
	bl Video_GetActorSprite
	ldr r1, _08245E48 @ =0x0000015F
	adds r0, r4, #0
	bl FUN_0822b20c
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sb
	movs r5, #0
	add r6, sp, #0x10
	add r0, sp, #0x18
	mov sl, r0
	movs r7, #0
_08245D46:
	adds r0, r4, #0
	movs r1, #0xac
	lsls r1, r1, #2
	add r1, sb
	movs r2, #1
	bl FUN_0822a4b0
	movs r0, #8
	subs r0, r0, r5
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	str r7, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _08245E4C @ =0x05000002
	bl CpuSet
	adds r5, #1
	adds r4, #0x2c
	cmp r5, #8
	ble _08245D46
	mov r7, sb
	adds r7, #0xd4
	ldr r2, _08245E50 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x20
	orrs r0, r4
	ldr r1, _08245E54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [r6, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r6, #4]
	movs r5, #0
	str r5, [sp, #0x18]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08245E58 @ =0x00004005
	movs r3, #0x10
	str r3, [sp]
	str r6, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x14
	add r0, sb
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08245E5C @ =FUN_08245c80
	adds r0, r7, #0
	mov r2, sb
	bl FUN_0823651c
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	subs r7, #0x50
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x64
	strh r0, [r6, #2]
	strh r4, [r6, #4]
	add r0, sp, #0x18
	strh r5, [r0]
	mov r1, sl
	strh r5, [r1, #2]
	strh r5, [r1, #4]
	ldr r2, _08245E60 @ =0x00002001
	movs r3, #0x10
	str r3, [sp]
	str r6, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08245E64 @ =FUN_08245cf8
	adds r0, r7, #0
	mov r2, sb
	bl FUN_0823651c
	ldr r0, [sp, #0x20]
	ldrh r1, [r0, #0x1c]
	str r5, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	movs r3, #0x10
	bl FUN_082364f8
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08245E44: .4byte 0x00008202
_08245E48: .4byte 0x0000015F
_08245E4C: .4byte 0x05000002
_08245E50: .4byte 0xFFFF0000
_08245E54: .4byte 0x0000FFFF
_08245E58: .4byte 0x00004005
_08245E5C: .4byte FUN_08245c80
_08245E60: .4byte 0x00002001
_08245E64: .4byte FUN_08245cf8
