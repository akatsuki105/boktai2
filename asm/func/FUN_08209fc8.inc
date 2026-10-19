	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820A034 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08209FE0
	b _0820A242
_08209FE0:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #8
	bl VM_GetNamedArgValue
	adds r7, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0820A040
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820A038 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820A03C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820A04A
	.align 2, 0
_0820A034: .4byte 0x03002B50
_0820A038: .4byte 0xFFFF0000
_0820A03C: .4byte 0x0000FFFF
_0820A040:
	ldr r1, _0820A15C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820A04A:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl Entity286FNode_Alloc
	adds r4, r0, #0
	cmp r4, #0
	bne _0820A068
	b _0820A242
_0820A068:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820A078
	b _0820A242
_0820A078:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820A160 @ =0x0000E02E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820A08E
	b _0820A242
_0820A08E:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl MsgQueue_Register
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820A164 @ =FUN_08209dd0
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A168 @ =FUN_08209f8c
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A16C @ =FUN_08209dc4
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A170 @ =FUN_08209e0c
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A174 @ =FUN_08209fac
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A178 @ =FUN_08209fb8
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820A160 @ =0x0000E02E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl Entity286F_LinkNode
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820A1AC
	cmp r5, #1
	bgt _0820A17C
	cmp r5, #0
	beq _0820A182
	b _0820A242
	.align 2, 0
_0820A15C: .4byte 0xFFFF0000
_0820A160: .4byte 0x0000E02E
_0820A164: .4byte FUN_08209dd0
_0820A168: .4byte FUN_08209f8c
_0820A16C: .4byte FUN_08209dc4
_0820A170: .4byte FUN_08209e0c
_0820A174: .4byte FUN_08209fac
_0820A178: .4byte FUN_08209fb8
_0820A17C:
	cmp r5, #2
	beq _0820A1E4
	b _0820A242
_0820A182:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820A1A8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820A240
	.align 2, 0
_0820A1A8: .4byte FUN_080421bc
_0820A1AC:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820A1E0 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl Entity286FNode_HideShadow
	b _0820A242
	.align 2, 0
_0820A1E0: .4byte FUN_08042178
_0820A1E4:
	ldr r1, _0820A214 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _0820A218 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820A220
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A21C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820A234
	.align 2, 0
_0820A214: .4byte 0x00000217
_0820A218: .4byte 0x000001EF
_0820A21C: .4byte FUN_080421bc
_0820A220:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A254 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820A234:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_0820A240:
	strb r7, [r4, #0x18]
_0820A242:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820A254: .4byte FUN_08042868
