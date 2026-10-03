	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08043E6A
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xd
	strb r0, [r4, #5]
_08043E6A:
	ldr r1, _08043EE4 @ =0x00000434
	adds r0, r2, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08043EC6
	adds r3, r4, #0
	adds r3, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r4, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043E90
	rsbs r1, r1, #0
_08043E90:
	cmp r1, r5
	bge _08043EBE
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043EA4
	rsbs r1, r1, #0
_08043EA4:
	cmp r1, #0xff
	bgt _08043EBE
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043EB8
	rsbs r0, r0, #0
_08043EB8:
	movs r1, #1
	cmp r0, r5
	blt _08043EC0
_08043EBE:
	movs r1, #0
_08043EC0:
	movs r5, #1
	cmp r1, #0
	bne _08043EC8
_08043EC6:
	movs r5, #0
_08043EC8:
	cmp r5, #0
	beq _08043EEC
	ldrb r1, [r4, #4]
	ldr r6, _08043EE8 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _08043F06
	.align 2, 0
_08043EE4: .4byte 0x00000434
_08043EE8: .4byte 0x00000227
_08043EEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08043F00
	adds r0, r4, #0
	bl FUN_08043510
	strb r0, [r4, #4]
	str r5, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_08043F00:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_08043F06:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
