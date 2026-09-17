	push {r4, r5, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823CFDC @ =0xFFFF0000
	lsrs r0, r0, #0x10
	str r0, [sp]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sp
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0823CFD8
	cmp r1, #0
	blt _0823CFD8
	ldr r0, _0823CFE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823CFD8
	ldr r0, _0823CFE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823CFE8
_0823CFD8:
	movs r4, #0
	b _0823CFF6
	.align 2, 0
_0823CFDC: .4byte 0xFFFF0000
_0823CFE0: .4byte 0x030046A8
_0823CFE4: .4byte 0x030046AC
_0823CFE8:
	ldr r0, _0823D008 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823CFF6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D00C
	adds r0, #4
	b _0823D018
	.align 2, 0
_0823D008: .4byte 0x030046A4
_0823D00C:
	ldr r0, _0823D038 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D018:
	ldrb r4, [r0]
	lsrs r4, r4, #4
	add r5, sp, #8
	adds r0, r5, #0
	bl FUN_0823167c
	adds r0, r5, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	adds r0, r4, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D038: .4byte 0x030046A4
