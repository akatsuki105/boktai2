	push {r4, r5, lr}
	sub sp, #8
	bl FUN_0807afe8
	ldr r1, _0807D3AC @ =0x03002BE0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	cmp r5, #0
	beq _0807D3A4
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0807D3A4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0807D3B0 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r4
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0807D3B4 @ =0x0000FFFF
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl FUN_0807d164
	adds r4, r0, #0
	bl FUN_0807d180
	adds r2, r0, #0
	adds r0, r5, #0
	mov r1, sp
	adds r3, r4, #0
	bl FUN_0807ba94
	adds r0, r5, #0
	bl FUN_08072640
_0807D3A4:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0807D3AC: .4byte 0x03002BE0
_0807D3B0: .4byte 0xFFFF0000
_0807D3B4: .4byte 0x0000FFFF
