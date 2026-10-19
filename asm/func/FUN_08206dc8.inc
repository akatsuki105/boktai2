	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08206E34 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08206DE0
	b _082070A8
_08206DE0:
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #2
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08206E40
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08206E38 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08206E3C @ =0x0000FFFF
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
	b _08206E4A
	.align 2, 0
_08206E34: .4byte 0x03002B50
_08206E38: .4byte 0xFFFF0000
_08206E3C: .4byte 0x0000FFFF
_08206E40:
	ldr r1, _08206F58 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08206E4A:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	ldr r0, _08206F5C @ =0x0000DFDE
	mov sl, r0
	movs r7, #0
	mov r0, r8
	adds r1, r5, #0
	bl Entity286FNode_Alloc
	adds r5, r0, #0
	cmp r5, #0
	bne _08206E6A
	b _082070A8
_08206E6A:
	mov r1, r8
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08206E7A
	b _082070A8
_08206E7A:
	str r7, [sp]
	adds r0, r5, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _08206E8E
	b _082070A8
_08206E8E:
	adds r0, r5, #0
	adds r0, #0x5c
	movs r1, #0xaf
	lsls r1, r1, #1
	movs r4, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r1, r8
	movs r2, #5
	bl MsgQueue_Register
	adds r0, r5, #0
	adds r0, #0x61
	strb r6, [r0]
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	ldr r1, _08206F60 @ =FUN_08206b0c
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F64 @ =FUN_08206d8c
	subs r2, #0x14
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F68 @ =FUN_082068bc
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F6C @ =FUN_08206b48
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F70 @ =FUN_08206dac
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F74 @ =FUN_08206db8
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	mov r0, sb
	adds r1, r5, #0
	mov r2, sl
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r5, #0
	bl Entity286F_LinkNode
	mov r0, sb
	adds r1, r5, #0
	bl FUN_08041e10
	adds r6, r5, #0
	adds r6, #0x20
	strb r4, [r6, #4]
	movs r0, #0x69
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #4
	bls _08206F4C
	b _082070A8
_08206F4C:
	lsls r0, r0, #2
	ldr r1, _08206F78 @ =_08206F7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08206F58: .4byte 0xFFFF0000
_08206F5C: .4byte 0x0000DFDE
_08206F60: .4byte FUN_08206b0c
_08206F64: .4byte FUN_08206d8c
_08206F68: .4byte FUN_082068bc
_08206F6C: .4byte FUN_08206b48
_08206F70: .4byte FUN_08206dac
_08206F74: .4byte FUN_08206db8
_08206F78: .4byte _08206F7C
_08206F7C: @ jump table
	.4byte _08206F90 @ case 0
	.4byte _08206FB8 @ case 1
	.4byte _08206FEC @ case 2
	.4byte _08207050 @ case 3
	.4byte _08207084 @ case 4
_08206F90:
	movs r2, #1
	movs r1, #0
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r2, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _08206FB4 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	b _082070A6
	.align 2, 0
_08206FB4: .4byte FUN_080421bc
_08206FB8:
	movs r2, #0
	strb r2, [r5, #2]
	strb r2, [r5, #3]
	strb r2, [r5, #4]
	str r2, [r5, #0x14]
	movs r1, #1
	strb r1, [r5, #8]
	ldr r3, _08206FE8 @ =FUN_08042178
	strb r1, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r3, [r0]
	str r2, [r5, #0x10]
	strb r1, [r5, #9]
	strb r2, [r5, #0x18]
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055ef8
	adds r0, r5, #0
	bl Entity286FNode_HideShadow
	b _082070A8
	.align 2, 0
_08206FE8: .4byte FUN_08042178
_08206FEC:
	ldr r1, _0820701C @ =0x00000217
	adds r0, r5, r1
	movs r4, #0
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08207020 @ =0x000001EF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08207028
	adds r0, r5, #0
	bl FUN_08043510
	strb r4, [r5, #2]
	strb r4, [r5, #3]
	strb r0, [r5, #4]
	str r4, [r5, #0x14]
	strb r6, [r5, #8]
	ldr r1, _08207024 @ =FUN_080421bc
	movs r0, #2
	b _08207038
	.align 2, 0
_0820701C: .4byte 0x00000217
_08207020: .4byte 0x000001EF
_08207024: .4byte FUN_080421bc
_08207028:
	movs r0, #6
	strb r4, [r5, #2]
	strb r4, [r5, #3]
	strb r0, [r5, #4]
	str r4, [r5, #0x14]
	strb r6, [r5, #8]
	ldr r1, _0820704C @ =FUN_08042868
	movs r0, #7
_08207038:
	strb r0, [r5, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	str r4, [r5, #0x10]
	strb r6, [r5, #9]
	strb r4, [r5, #0x18]
	b _082070A8
	.align 2, 0
_0820704C: .4byte FUN_08042868
_08207050:
	ldr r4, _0820707C @ =0x00000217
	adds r0, r5, r4
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	strb r2, [r6, #4]
	movs r0, #0x16
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _08207080 @ =FUN_08042868
	movs r0, #7
	strb r0, [r5, #6]
	adds r4, #0xb5
	adds r0, r5, r4
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	b _082070A6
	.align 2, 0
_0820707C: .4byte 0x00000217
_08207080: .4byte FUN_08042868
_08207084:
	movs r0, #0x12
	movs r1, #0
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	movs r3, #1
	strb r3, [r5, #8]
	ldr r2, _082070B8 @ =FUN_08206ad4
	movs r0, #0x11
	strb r0, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	str r1, [r5, #0x10]
	strb r3, [r5, #9]
_082070A6:
	strb r1, [r5, #0x18]
_082070A8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082070B8: .4byte FUN_08206ad4
