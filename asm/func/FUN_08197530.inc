	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x4d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _081975AC
	bl VM_GetPC
	cmp r0, #0
	beq _0819754E
	bl VM_GetValue
	adds r1, r0, #0
	b _08197550
_0819754E:
	movs r1, #0x3c
_08197550:
	ldr r2, _08197568 @ =0x00000AC4
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _0819756C
	bl VM_GetValue
	adds r1, r0, #0
	b _0819756E
	.align 2, 0
_08197568: .4byte 0x00000AC4
_0819756C:
	movs r1, #2
_0819756E:
	ldr r2, _08197584 @ =0x00000AC8
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08197588
	bl VM_GetValue
	adds r1, r0, #0
	b _0819758A
	.align 2, 0
_08197584: .4byte 0x00000AC8
_08197588:
	movs r1, #0x50
_0819758A:
	ldr r2, _081975A0 @ =0x00000ACA
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081975A4
	bl VM_GetValue
	adds r1, r0, #0
	b _081975A6
	.align 2, 0
_081975A0: .4byte 0x00000ACA
_081975A4:
	movs r1, #1
_081975A6:
	ldr r2, _081975B4 @ =0x00000ACC
	adds r0, r4, r2
	strh r1, [r0]
_081975AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081975B4: .4byte 0x00000ACC
