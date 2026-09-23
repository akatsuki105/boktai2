	push {r4, lr}
	ldr r0, _08049F2C @ =0x030000C8
	ldr r0, [r0]
	cmp r0, #0
	beq _08049F52
	adds r4, r0, #0
	adds r4, #0x18
	movs r0, #0
	strb r0, [r4, #0xd]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08049F52
	b _08049F46
	.align 2, 0
_08049F2C: .4byte 0x030000C8
_08049F30:
	bl Script_GetValue
	ldrb r2, [r4, #0xd]
	lsls r2, r2, #2
	adds r1, r4, #0
	adds r1, #0xc4
	adds r1, r1, r2
	str r0, [r1]
	ldrb r0, [r4, #0xd]
	adds r0, #1
	strb r0, [r4, #0xd]
_08049F46:
	bl VM_GetPC
	cmp r0, #0
	bne _08049F30
	movs r0, #0
	b _08049F56
_08049F52:
	movs r0, #1
	rsbs r0, r0, #0
_08049F56:
	pop {r4}
	pop {r1}
	bx r1
