	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r7, r0, #0
	cmp r7, #0
	beq _08019940
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080198D4
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080198CC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080198D0 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080198DE
	.align 2, 0
_080198CC: .4byte 0xFFFF0000
_080198D0: .4byte 0x0000FFFF
_080198D4:
	ldr r1, _08019934 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080198DE:
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #0x64
	adds r1, r4, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetNamedArgValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #8
	bl VM_GetNamedArgValue
	adds r5, r0, #0
	movs r0, #0x54
	movs r1, #0
	bl VM_GetNamedArgValue
	adds r4, r0, #0
	ldr r1, _08019938 @ =Entity99CA_Update
	ldr r2, _0801993C @ =Entity99CA_Destroy
	adds r0, r7, #0
	bl SetEntityRoutine
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #8
	mov r2, r8
	adds r3, r6, #0
	bl Entity99CA_Init
	cmp r0, #0
	bge _08019940
	adds r0, r7, #0
	bl KillEntity
	movs r0, #0
	b _08019942
	.align 2, 0
_08019934: .4byte 0xFFFF0000
_08019938: .4byte Entity99CA_Update
_0801993C: .4byte Entity99CA_Destroy
_08019940:
	adds r0, r7, #0
_08019942:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
