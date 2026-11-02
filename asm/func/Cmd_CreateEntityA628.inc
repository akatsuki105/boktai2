	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080A0FCC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A0FDA
	ldr r0, _080A0FD0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A0FD4
	movs r4, #1
	rsbs r4, r4, #0
	b _080A0FEE
	.align 2, 0
_080A0FCC: .4byte 0x030047A4
_080A0FD0: .4byte 0x03002C68
_080A0FD4:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
	b _080A0FEE
_080A0FDA:
	movs r0, #0x69
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A0FEC
	bl VM_GetValue
	adds r4, r0, #0
	b _080A0FEE
_080A0FEC:
	movs r4, #0
_080A0FEE:
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A1000
	bl VM_GetValue
	adds r2, r0, #0
	b _080A1002
_080A1000:
	movs r2, #1
_080A1002:
	adds r0, r5, #0
	adds r1, r4, #0
	bl EntityA628_Create
	pop {r4, r5}
	pop {r1}
	bx r1
