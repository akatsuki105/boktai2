	push {lr}
	ldr r0, _081E24A0 @ =0x03002C6C
	ldr r0, [r0]
	cmp r0, #0
	beq _081E24AE
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r0, #0x64]
	ands r0, r1
	cmp r0, #0
	beq _081E24A4
	movs r0, #1
	b _081E24A6
	.align 2, 0
_081E24A0: .4byte 0x03002C6C
_081E24A4:
	movs r0, #0
_081E24A6:
	cmp r0, #0
	bne _081E24AE
	movs r0, #0
	b _081E24B0
_081E24AE:
	movs r0, #1
_081E24B0:
	pop {r1}
	bx r1
