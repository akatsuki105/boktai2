	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r1, #0
_0801518E:
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	mov r2, r8
	adds r5, r2, r0
	ldrb r0, [r5]
	adds r7, r1, #1
	cmp r0, #0
	beq _080151C6
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x2c
_080151AC:
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080151C0
	movs r0, #0x2c
	muls r0, r4, r0
	adds r0, #0x70
	adds r0, r5, r0
	bl AuxSprite_Remove
_080151C0:
	adds r4, #1
	cmp r4, #5
	ble _080151AC
_080151C6:
	adds r1, r7, #0
	cmp r1, #3
	ble _0801518E
	ldr r1, _080151DC @ =0x0300005C
	movs r0, #0
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080151DC: .4byte 0x0300005C
