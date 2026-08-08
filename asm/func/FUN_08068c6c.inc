	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08068CC4 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08068C88
	ldr r2, _08068CC8 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08068C88
	movs r1, #1
_08068C88:
	cmp r1, #0
	bne _08068CC0
	ldr r3, _08068CCC @ =0x00000362
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r3, #2
	adds r2, r4, r3
	subs r1, r1, r0
	ldrh r2, [r2]
	adds r1, r1, r2
	ldr r0, _08068CD0 @ =0x03002C00
	ldr r0, [r0]
	ldrh r0, [r0, #0x1e]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _08068CD4
_08068CC0:
	movs r1, #0x10
	b _08068CDA
	.align 2, 0
_08068CC4: .4byte 0x00000446
_08068CC8: .4byte 0x00000442
_08068CCC: .4byte 0x00000362
_08068CD0: .4byte 0x03002C00
_08068CD4:
	cmp r1, #5
	bgt _08068CDA
	movs r1, #6
_08068CDA:
	ldr r2, _08068D0C @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _08068CF0
	ldr r3, _08068D10 @ =0x000004C7
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08068CF0
	subs r1, #3
_08068CF0:
	ldr r0, _08068D14 @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _08068CFC
	subs r1, r1, r0
_08068CFC:
	cmp r1, #1
	bgt _08068D02
	movs r1, #2
_08068D02:
	adds r0, r1, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08068D0C: .4byte 0x000004C5
_08068D10: .4byte 0x000004C7
_08068D14: .4byte 0x00000402
