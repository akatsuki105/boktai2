	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DCDAC @ =0x00000834
	adds r4, r5, r0
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe9
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r1, _081DCDB0 @ =0x00000704
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081DCDB4 @ =0x00000828
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _081DCDB8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DCDBC
	movs r0, #1
	rsbs r0, r0, #0
	b _081DCDC0
	.align 2, 0
_081DCDAC: .4byte 0x00000834
_081DCDB0: .4byte 0x00000704
_081DCDB4: .4byte 0x00000828
_081DCDB8: .4byte 0x03002C68
_081DCDBC:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_081DCDC0:
	cmp r0, #1
	beq _081DCDD2
	cmp r0, #1
	ble _081DCDEC
	cmp r0, #2
	beq _081DCDDC
	cmp r0, #3
	beq _081DCDE2
	b _081DCDEC
_081DCDD2:
	ldr r0, _081DCDD8 @ =0x0000075C
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDD8: .4byte 0x0000075C
_081DCDDC:
	movs r2, #0xec
	lsls r2, r2, #3
	b _081DCDF0
_081DCDE2:
	ldr r0, _081DCDE8 @ =0x00000764
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDE8: .4byte 0x00000764
_081DCDEC:
	movs r2, #0xeb
	lsls r2, r2, #3
_081DCDF0:
	adds r1, r5, r2
_081DCDF2:
	ldr r0, _081DCE0C @ =0x00007FFF
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, _081DCE10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCE0C: .4byte 0x00007FFF
_081DCE10: .4byte 0x03004290
