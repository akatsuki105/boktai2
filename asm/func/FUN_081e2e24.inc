	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _081E2E78 @ =0x00001590
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	ldr r2, _081E2E7C @ =0x00000E28
	adds r1, r4, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	bl Textbox_LookupString
	movs r3, #0
	ldrb r1, [r0]
	cmp r1, #0
	beq _081E2E68
	cmp r1, #0x3c
	beq _081E2E68
	ldr r1, _081E2E80 @ =0x000015A4
	adds r5, r4, r1
	adds r2, r0, #0
_081E2E50:
	adds r1, r5, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r3, #1
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E2E68
	cmp r3, #0xf
	bgt _081E2E68
	cmp r0, #0x3c
	bne _081E2E50
_081E2E68:
	ldr r2, _081E2E80 @ =0x000015A4
	adds r0, r4, r2
	adds r0, r0, r3
	movs r1, #0
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E2E78: .4byte 0x00001590
_081E2E7C: .4byte 0x00000E28
_081E2E80: .4byte 0x000015A4
