	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r2, _08041514 @ =0x00000212
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08041570
	cmp r1, #1
	bne _08041518
	movs r5, #0
	b _0804151E
	.align 2, 0
_08041514: .4byte 0x00000212
_08041518:
	cmp r1, #3
	bne _08041570
	movs r5, #2
_0804151E:
	adds r0, r4, #0
	adds r0, #0xd0
	mov r1, sp
	bl FUN_08055d48
	cmp r0, #0
	beq _08041570
	movs r1, #0xaf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r2, #4
	adds r3, r0, r5
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r1, [sp]
	cmp r0, r1
	bne _08041558
	ldr r0, _08041554 @ =0x085AB360
	ldrb r1, [r2, #3]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
	b _08041570
	.align 2, 0
_08041554: .4byte 0x085AB360
_08041558:
	movs r0, #1
	ldrsb r0, [r3, r0]
	cmp r0, r1
	bne _08041570
	ldr r0, _08041578 @ =0x085AB360
	ldrb r1, [r2, #3]
	lsls r1, r1, #2
	adds r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	bl PlaySound_082406e0
_08041570:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08041578: .4byte 0x085AB360
