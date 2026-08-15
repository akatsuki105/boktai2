	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	bl FUN_0807afe8
	ldr r1, _0807D464 @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r6, [r0]
	cmp r6, #0
	beq _0807D4E0
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0807D468
	bl Script_GetValue
	adds r5, r0, #0
	b _0807D46A
	.align 2, 0
_0807D464: .4byte 0x03002BE0
_0807D468:
	movs r5, #0
_0807D46A:
	bl FUN_0807d164
	mov r8, r0
	bl FUN_0807d180
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0807D4CC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0807D4C4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0807D4C8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	str r7, [sp]
	adds r0, r6, #0
	add r1, sp, #4
	mov r2, r8
	adds r3, r5, #0
	bl FUN_0807bb3c
	b _0807D4DA
	.align 2, 0
_0807D4C4: .4byte 0xFFFF0000
_0807D4C8: .4byte 0x0000FFFF
_0807D4CC:
	str r7, [sp]
	adds r0, r6, #0
	movs r1, #0
	mov r2, r8
	adds r3, r5, #0
	bl FUN_0807bb3c
_0807D4DA:
	adds r0, r6, #0
	bl FUN_08072640
_0807D4E0:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
