	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x20
_081F44CE:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F44DE
	movs r0, #1
	b _081F44E0
_081F44DE:
	movs r0, #0
_081F44E0:
	cmp r0, #0
	beq _081F4506
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _081F44F0
	adds r0, r4, #0
	bl AuxSprite_Remove
_081F44F0:
	ldr r1, _081F4520 @ =0x0000015B
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _081F4506
	adds r0, r4, #0
	adds r0, #0x64
	bl AuxShadow_Remove
_081F4506:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	ble _081F44CE
	movs r1, #0
	ldr r0, _081F4524 @ =0x030001F4
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081F4520: .4byte 0x0000015B
_081F4524: .4byte 0x030001F4
