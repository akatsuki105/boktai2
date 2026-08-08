	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	strb r0, [r4, #9]
	movs r1, #7
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08245CEA
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	mov r8, r0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08245CD0
	ldr r0, _08245CCC @ =0x00000229
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #6]
	b _08245CEA
	.align 2, 0
_08245CCC: .4byte 0x00000229
_08245CD0:
	movs r1, #0x7f
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08245CEA
	ldr r0, _08245CF4 @ =0x0000022A
	bl PlaySound_082406e0
	mov r0, r8
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r7, [r6, #6]
_08245CEA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08245CF4: .4byte 0x0000022A
