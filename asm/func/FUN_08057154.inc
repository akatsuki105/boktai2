	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	str r1, [sp, #0x1c]
	movs r0, #0
	strh r0, [r7, #0x24]
	ldr r0, _08057200 @ =0xFFFF0000
	mov sl, r0
	add r6, sp, #0xc
	ldr r1, _08057204 @ =0x00000D7C
	mov sb, r1
	add r5, sp, #0x14
	movs r0, #3
	mov r8, r0
_08057178:
	mov r1, sb
	adds r4, r7, r1
	ldr r0, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08057208 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r6, #4]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0x80
	lsls r0, r0, #0xe
	str r0, [sp, #0x14]
	ldr r0, [r5, #4]
	mov r1, sl
	ands r0, r1
	str r0, [r5, #4]
	movs r0, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0805720C @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	ldr r1, _08057210 @ =FUN_08056f90
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x50
	add sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _08057178
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057200: .4byte 0xFFFF0000
_08057204: .4byte 0x00000D7C
_08057208: .4byte 0x0000FFFF
_0805720C: .4byte 0x00002001
_08057210: .4byte FUN_08056f90
