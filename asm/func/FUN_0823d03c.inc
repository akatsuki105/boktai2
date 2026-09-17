	push {r4, r5, lr}
	sub sp, #0x10
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r4, _0823D088 @ =0xFFFF0000
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
	blt _0823D084
	cmp r1, #0
	blt _0823D084
	ldr r0, _0823D08C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0823D084
	ldr r0, _0823D090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0823D094
_0823D084:
	movs r4, #0
	b _0823D0A2
	.align 2, 0
_0823D088: .4byte 0xFFFF0000
_0823D08C: .4byte 0x030046A8
_0823D090: .4byte 0x030046AC
_0823D094:
	ldr r0, _0823D0B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0823D0A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0823D0B8
	adds r0, #4
	b _0823D0C4
	.align 2, 0
_0823D0B4: .4byte 0x030046A4
_0823D0B8:
	ldr r0, _0823D0E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0823D0C4:
	ldrh r5, [r0, #2]
	add r4, sp, #8
	adds r0, r4, #0
	bl FUN_0823167c
	adds r0, r4, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823D0E4: .4byte 0x030046A4
