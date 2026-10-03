	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r2, r1, #0
	adds r6, r2, #0
	adds r6, #0x5c
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08043BE6
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #9
	strb r0, [r2, #5]
_08043BE6:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08043C8E
	ldr r7, _08043C68 @ =0x00000434
	adds r0, r3, r7
	ldr r3, [r0]
	cmp r3, #0
	beq _08043C8E
	adds r4, r2, #0
	adds r4, #0x64
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r5, [r0]
	movs r7, #0
	ldrsh r1, [r3, r7]
	movs r7, #8
	ldrsh r0, [r6, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043C18
	rsbs r1, r1, #0
_08043C18:
	cmp r1, r5
	bge _08043C46
	movs r0, #2
	ldrsh r1, [r3, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043C2C
	rsbs r1, r1, #0
_08043C2C:
	cmp r1, #0xff
	bgt _08043C46
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043C40
	rsbs r0, r0, #0
_08043C40:
	movs r3, #1
	cmp r0, r5
	blt _08043C48
_08043C46:
	movs r3, #0
_08043C48:
	cmp r3, #0
	bne _08043C88
	ldr r6, _08043C6C @ =0x00000216
	adds r0, r2, r6
	ldrb r1, [r0]
	cmp r1, #0
	beq _08043C74
	ldr r7, _08043C70 @ =0x00000215
	adds r0, r2, r7
	ldrb r0, [r0]
	strb r0, [r2, #0x1b]
	movs r0, #3
	strb r0, [r2, #4]
	str r3, [r2, #0x14]
	b _08043C7E
	.align 2, 0
_08043C68: .4byte 0x00000434
_08043C6C: .4byte 0x00000216
_08043C70: .4byte 0x00000215
_08043C74:
	ldr r3, _08043C84 @ =0x00000227
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r2, #4]
	str r1, [r2, #0x14]
_08043C7E:
	movs r0, #1
	strb r0, [r2, #8]
	b _08043C8E
	.align 2, 0
_08043C84: .4byte 0x00000227
_08043C88:
	ldr r0, [r2, #0x14]
	adds r0, #1
	str r0, [r2, #0x14]
_08043C8E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
