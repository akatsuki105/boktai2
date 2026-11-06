	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DC3B6
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r0, _080DC394 @ =0x085AD32C
	mov r8, r0
_080DC382:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC398
	movs r0, #1
	b _080DC39A
	.align 2, 0
_080DC394: .4byte 0x085AD32C
_080DC398:
	movs r0, #0
_080DC39A:
	cmp r0, #0
	beq _080DC3AE
	ldrb r0, [r4, #0x16]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DC3AE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC382
_080DC3B6:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
