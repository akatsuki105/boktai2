	push {r4, r5, r6, r7, lr}
	ldr r0, _08041B50 @ =0x03002B50
	ldr r6, [r0]
	cmp r6, #0
	beq _08041B4A
	ldr r3, [r6, #0x28]
	lsls r0, r3, #2
	adds r1, r6, #0
	adds r1, #0x2c
	adds r0, r1, r0
	ldr r2, [r0]
	lsls r0, r2, #2
	adds r0, r1, r0
	ldr r0, [r0]
	adds r7, r1, #0
	cmp r0, #7
	bls _08041B54
_08041B4A:
	movs r0, #1
	rsbs r0, r0, #0
	b _08041BCE
	.align 2, 0
_08041B50: .4byte 0x03002B50
_08041B54:
	lsls r0, r3, #9
	adds r0, #0x34
	adds r0, r6, r0
	lsls r1, r2, #6
	adds r5, r0, r1
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	movs r4, #0
	strh r0, [r5]
	movs r0, #0x6b
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r5, #2]
	strb r4, [r5, #3]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r5, #4]
	movs r0, #0x61
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r5, #6]
	strb r4, [r5, #7]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08041BBA
_08041B96:
	bl VM_GetPC
	cmp r0, #0
	beq _08041BBA
	bl VM_GetValue
	ldrb r2, [r5, #7]
	adds r1, r2, #1
	strb r1, [r5, #7]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x17
	adds r1, r5, #0
	adds r1, #8
	adds r1, r1, r2
	strh r0, [r1]
	ldrb r0, [r5, #7]
	cmp r0, #7
	bls _08041B96
_08041BBA:
	adds r0, r5, #0
	bl MsgPacket_Send
	ldr r1, [r6, #0x28]
	lsls r1, r1, #2
	adds r1, r7, r1
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
_08041BCE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
