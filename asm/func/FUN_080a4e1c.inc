	push {r4, r5, r6, r7, lr}
	ldr r0, _080A4E38 @ =0x03002C44
	ldr r4, [r0]
	cmp r4, #0
	beq _080A4E70
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A4E46
	bl VM_GetValue
	adds r5, r0, #0
	b _080A4E48
	.align 2, 0
_080A4E38: .4byte 0x03002C44
_080A4E3C:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	b _080A4E72
_080A4E46:
	movs r5, #0
_080A4E48:
	movs r3, #0
	ldrb r0, [r4, #0x18]
	cmp r3, r0
	bge _080A4E70
	adds r6, r0, #0
	movs r7, #0x92
	lsls r7, r7, #1
	adds r1, r4, r7
	adds r2, r4, #0
	movs r4, #0x88
	lsls r4, r4, #1
_080A4E5E:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	beq _080A4E3C
	adds r1, r1, r4
	adds r2, r2, r4
	adds r3, #1
	cmp r3, r6
	blt _080A4E5E
_080A4E70:
	movs r0, #0
_080A4E72:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
