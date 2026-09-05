	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08240E4A
	adds r4, r5, #0
	adds r4, #0x98
	b _08240E42
_08240E3C:
	bl Script_GetValue
	stm r4!, {r0}
_08240E42:
	bl VM_GetPC
	cmp r0, #0
	bne _08240E3C
_08240E4A:
	bl FUN_08240b44
	ldr r0, _08240E5C @ =0x03001700
	str r5, [r0]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08240E5C: .4byte 0x03001700
