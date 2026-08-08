	push {r4, lr}
	adds r1, r0, #0
	ldr r2, _0807271C @ =0x000004AD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08072716
	ldr r0, _08072720 @ =0x000004AE
	adds r4, r1, r0
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _08072716
	adds r0, r1, #0
	bl FUN_080612d8
	movs r0, #0
	strb r0, [r4]
_08072716:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807271C: .4byte 0x000004AD
_08072720: .4byte 0x000004AE
