	push {r4, r5, r6, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _08043982
	movs r0, #0
	strb r0, [r3, #8]
	strb r0, [r3, #7]
	movs r0, #4
	strb r0, [r3, #5]
	ldr r1, _080439F8 @ =0x00000226
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #5
	lsls r0, r0, #5
	strb r0, [r3, #0x1b]
_08043982:
	ldr r6, _080439FC @ =0x00000434
	adds r0, r2, r6
	ldr r2, [r0]
	cmp r2, #0
	beq _080439DE
	adds r4, r3, #0
	adds r4, #0x64
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r5, [r0]
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080439A8
	rsbs r1, r1, #0
_080439A8:
	cmp r1, r5
	bge _080439D6
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080439BC
	rsbs r1, r1, #0
_080439BC:
	cmp r1, #0xff
	bgt _080439D6
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080439D0
	rsbs r0, r0, #0
_080439D0:
	movs r2, #1
	cmp r0, r5
	blt _080439D8
_080439D6:
	movs r2, #0
_080439D8:
	movs r1, #1
	cmp r2, #0
	bne _080439E0
_080439DE:
	movs r1, #0
_080439E0:
	cmp r1, #0
	beq _08043A04
	ldrb r1, [r3, #4]
	ldr r6, _08043A00 @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	b _08043A10
	.align 2, 0
_080439F8: .4byte 0x00000226
_080439FC: .4byte 0x00000434
_08043A00: .4byte 0x00000227
_08043A04:
	ldrb r0, [r3, #7]
	cmp r0, #0
	beq _08043A16
	movs r0, #7
	strb r0, [r3, #4]
	str r1, [r3, #0x14]
_08043A10:
	movs r0, #1
	strb r0, [r3, #8]
	b _08043A1C
_08043A16:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08043A1C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
