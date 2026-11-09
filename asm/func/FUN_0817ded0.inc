	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, r8
	ldr r6, [r0]
	movs r0, #0x69
	bl VM_SeekToNamedArg
	adds r1, r0, #0
	cmp r1, #0
	beq _0817DF50
	bl VM_GetPC
	cmp r0, #0
	beq _0817DEFC
	bl VM_GetValue
	adds r1, r0, #0
	b _0817DEFE
_0817DEFC:
	movs r1, #0
_0817DEFE:
	ldr r2, _0817DF1C @ =0x000007AE
	adds r0, r6, r2
	strh r1, [r0]
	movs r4, #0
_0817DF06:
	ldr r3, _0817DF20 @ =0x000007A4
	adds r0, r6, r3
	adds r5, r0, r4
	bl VM_GetPC
	cmp r0, #0
	beq _0817DF24
	bl VM_GetValue
	b _0817DF2A
	.align 2, 0
_0817DF1C: .4byte 0x000007AE
_0817DF20: .4byte 0x000007A4
_0817DF24:
	movs r1, #1
	rsbs r1, r1, #0
	adds r0, r1, #0
_0817DF2A:
	strb r0, [r5]
	lsls r0, r4, #1
	movs r2, #0xf5
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r5, r1, r0
	bl VM_GetPC
	cmp r0, #0
	beq _0817DF44
	bl VM_GetValue
	b _0817DF46
_0817DF44:
	movs r0, #0
_0817DF46:
	strh r0, [r5]
	adds r4, #1
	cmp r4, #2
	ble _0817DF06
	b _0817DF78
_0817DF50:
	ldr r3, _0817DFBC @ =0x000007AE
	adds r0, r6, r3
	strh r1, [r0]
	movs r4, #0
	ldr r0, _0817DFC0 @ =0x000007A4
	adds r3, r6, r0
	movs r7, #0xff
	movs r1, #0xf5
	lsls r1, r1, #3
	adds r2, r6, r1
	movs r5, #0
_0817DF66:
	adds r1, r3, r4
	ldrb r0, [r1]
	orrs r0, r7
	strb r0, [r1]
	strh r5, [r2]
	adds r2, #2
	adds r4, #1
	cmp r4, #2
	ble _0817DF66
_0817DF78:
	movs r0, #0x54
	movs r1, #0x78
	bl VM_GetNamedArgValue
	ldr r2, _0817DFC4 @ =0x000008A8
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xc2
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r1, #0xa
	bl Div
	lsls r2, r0, #1
	adds r0, r2, r0
	movs r3, #0x8b
	lsls r3, r3, #4
	adds r1, r6, r3
	strh r0, [r1]
	lsls r0, r0, #1
	adds r3, #2
	adds r1, r6, r3
	strh r0, [r1]
	ldr r1, _0817DFC8 @ =0x000008B4
	adds r0, r6, r1
	strh r2, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817DFBC: .4byte 0x000007AE
_0817DFC0: .4byte 0x000007A4
_0817DFC4: .4byte 0x000008A8
_0817DFC8: .4byte 0x000008B4
