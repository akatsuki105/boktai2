	push {lr}
	adds r1, r0, #0
	adds r0, #0xd6
	ldrh r2, [r0]
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	bne _081D2226
	adds r0, r1, #0
	adds r0, #0xc8
	ldrh r0, [r0]
	cmp r0, #2
	bgt _081D21FC
	cmp r0, #1
	bge _081D2212
	cmp r0, #0
	beq _081D2208
	b _081D2220
_081D21FC:
	cmp r0, #3
	bne _081D2220
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _081D2212
_081D2208:
	movs r0, #0xac
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D2226
_081D2212:
	ldr r0, _081D221C @ =0x00000261
	bl PlaySound_082406e0
	b _081D2226
	.align 2, 0
_081D221C: .4byte 0x00000261
_081D2220:
	ldr r0, _081D222C @ =0x00000261
	bl PlaySound_082406e0
_081D2226:
	pop {r0}
	bx r0
	.align 2, 0
_081D222C: .4byte 0x00000261
