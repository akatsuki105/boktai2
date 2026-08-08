	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _080DF968 @ =0x000001B3
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DF912
	b _080DFA0E
_080DF912:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DFA12
	ldr r0, _080DF96C @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	ldr r2, _080DF970 @ =0x0000019D
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _080DF978
	ldr r3, _080DF974 @ =0xFFFFFF00
	adds r1, r1, r3
	b _080DF986
	.align 2, 0
_080DF968: .4byte 0x000001B3
_080DF96C: .4byte 0x03002BE0
_080DF970: .4byte 0x0000019D
_080DF974: .4byte 0xFFFFFF00
_080DF978:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _080DF986
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_080DF986:
	adds r0, r1, #0
	cmp r1, #0
	bge _080DF98E
	rsbs r0, r1, #0
_080DF98E:
	cmp r0, #8
	ble _080DF9CC
	cmp r1, #0
	ble _080DF9B0
	ldr r2, _080DF9A8 @ =0x0000019D
	adds r1, r5, r2
	ldr r3, _080DF9AC @ =0x0000019F
	adds r0, r5, r3
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	b _080DF9E0
	.align 2, 0
_080DF9A8: .4byte 0x0000019D
_080DF9AC: .4byte 0x0000019F
_080DF9B0:
	ldr r3, _080DF9C4 @ =0x0000019D
	adds r2, r5, r3
	ldr r0, _080DF9C8 @ =0x0000019F
	adds r1, r5, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r2]
	b _080DF9E2
	.align 2, 0
_080DF9C4: .4byte 0x0000019D
_080DF9C8: .4byte 0x0000019F
_080DF9CC:
	movs r2, #0xcf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	lsrs r0, r0, #1
	strb r0, [r1]
	ldr r3, _080DFA1C @ =0x0000019F
	adds r1, r5, r3
	ldrb r0, [r1]
	lsrs r0, r0, #1
_080DF9E0:
	strb r0, [r1]
_080DF9E2:
	movs r0, #0xcf
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DF9F2
	subs r0, #1
	strb r0, [r1]
_080DF9F2:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _080DFA12
	ldr r2, _080DFA1C @ =0x0000019F
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DFA12
_080DFA0E:
	subs r0, #1
	strb r0, [r1]
_080DFA12:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080DFA1C: .4byte 0x0000019F
