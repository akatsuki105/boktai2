	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080436E6
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl EntityMsgBox_EndWait
_080436E6:
	ldr r2, _08043760 @ =0x00000434
	adds r0, r5, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _08043742
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
	bge _0804370C
	rsbs r1, r1, #0
_0804370C:
	cmp r1, r5
	bge _0804373A
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r3, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08043720
	rsbs r1, r1, #0
_08043720:
	cmp r1, #0xff
	bgt _0804373A
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08043734
	rsbs r0, r0, #0
_08043734:
	movs r1, #1
	cmp r0, r5
	blt _0804373C
_0804373A:
	movs r1, #0
_0804373C:
	movs r0, #1
	cmp r1, #0
	bne _08043744
_08043742:
	movs r0, #0
_08043744:
	cmp r0, #0
	beq _08043768
	ldrb r1, [r4, #4]
	ldr r6, _08043764 @ =0x00000227
	adds r0, r4, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r4, #4]
	str r2, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0804376E
	.align 2, 0
_08043760: .4byte 0x00000434
_08043764: .4byte 0x00000227
_08043768:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_0804376E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
