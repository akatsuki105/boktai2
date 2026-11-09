	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081716E4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081716E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081716EA
	.align 2, 0
_081716E4: .4byte 0x0000046D
_081716E8:
	movs r0, #0
_081716EA:
	cmp r0, #0
	beq _081716F6
	adds r0, r4, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
_081716F6:
	ldr r1, _08171710 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08171708
	ldr r0, _08171714 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08171708:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08171710: .4byte 0x0000046E
_08171714: .4byte 0x0000046B
