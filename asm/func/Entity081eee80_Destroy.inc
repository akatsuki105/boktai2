	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r4, #0x38
	adds r5, r0, #0
	adds r5, #0x77
	movs r6, #0x7f
_081EEE30:
	ldrb r0, [r5]
	cmp r0, #1
	bne _081EEE42
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081EEE42
	adds r0, r4, #0
	bl AuxSprite_Remove
_081EEE42:
	adds r4, #0x40
	adds r5, #0x40
	subs r6, #1
	cmp r6, #0
	bge _081EEE30
	movs r1, #0
	ldr r0, _081EEE5C @ =0x030001D8
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE5C: .4byte 0x030001D8
