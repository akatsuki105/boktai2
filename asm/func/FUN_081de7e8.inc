	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081ddab4
	cmp r0, #0
	bge _081DE800
	adds r0, r4, #0
	bl FUN_081ddbdc
	movs r0, #1
	rsbs r0, r0, #0
	b _081DE838
_081DE800:
	ldr r0, [r4, #0x34]
	cmp r0, #0x78
	bls _081DE836
	ldr r0, _081DE824 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DE82C
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081DE82C
	ldr r2, _081DE828 @ =FUN_081de844
	adds r0, r4, #0
	movs r1, #7
	bl Entity9A9F_SetState
	b _081DE836
	.align 2, 0
_081DE824: .4byte 0x03002C68
_081DE828: .4byte FUN_081de844
_081DE82C:
	ldr r2, _081DE840 @ =FUN_081de960
	adds r0, r4, #0
	movs r1, #8
	bl Entity9A9F_SetState
_081DE836:
	movs r0, #0
_081DE838:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DE840: .4byte FUN_081de960
